def docker_args = ''

pipeline {
    agent any
    options {
        timeout(10)
        timestamps()
    }
    triggers {
        cron('10 2 * * *')
    }
    stages {
        stage('clean ws') {
            steps {
                sh 'git clean -dfx'
            }
        }
        stage('SCM update (submodules)') {
            steps {
                sh 'git submodule sync --recursive'
                sh 'git submodule update --recursive --init'
            }
        }
        stage('Build docker image') {
            steps {
                script {
                    dockerImage = docker.build("jczconfig_build", "-f Dockerfile .")

                    docker_args = "--name jczconfig_build " +
                                  " -v " + env.HOME + ":" + env.HOME +
                                  " -e HOME=" + env.HOME
                }
            }
        }
        stage('cmake') {
            steps {
                script {
                    dockerImage.inside(docker_args) {
                        sh('source ./build_settings.sh && mkdir -p build && cd build && cmake ..')
                    }
                }
            }
        }
        stage('make') {
            steps {
                script {
                    dockerImage.inside(docker_args) {
                        sh('cd build && make -j$(nproc)')
                    }
                }
            }
        }
        stage('doxygen') {
            steps {
                script {
                    dockerImage.inside(docker_args) {
                        sh('doxygen')
                    }
                }
            }
        }
        stage('cppcheck') {
            steps {
                script {
                    dockerImage.inside(docker_args) {
                        sh('./cppcheck.sh')
                    }
                }
                publishCppcheck pattern:'build/cppcheck.xml'
            }
        }
        stage('test') {
            steps {
                script {
                    dockerImage.inside(docker_args) {
                        sh('cd build && CTEST_OUTPUT_ON_FAILURE=1 make test')
                    }
                }
            }
        }
        stage('coverage') {
            steps {
                script {
                    dockerImage.inside(docker_args) {
                        sh('./coverage.sh')
                    }
                }
            }
        }
    }
    post {
        always {
            junit "build/test/test*.xml"
            recordIssues enabledForFailure: true, aggregatingResults: true, tools: [gcc(), cppCheck(pattern:'**/cppcheck.xml'), doxygen()]
            step([$class: 'CoberturaPublisher', autoUpdateHealth: false, autoUpdateStability: false, coberturaReportFile: 'build/coverage.xml', failUnhealthy: false, failUnstable: false, maxNumberOfBuilds: 0, onlyStable: false, sourceEncoding: 'ASCII', zoomCoverageChart: false])
        }
        failure {
            slackSend color: "danger", message: "Job: ${env.JOB_NAME} with buildnumber ${env.BUILD_NUMBER} has failed: ${env.BUILD_URL}"
        }
        fixed {
            slackSend color: "good", message: "Job: ${env.JOB_NAME} with buildnumber ${env.BUILD_NUMBER} was successful: ${env.BUILD_URL}"
        }
    }
}
