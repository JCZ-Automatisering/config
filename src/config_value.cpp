/* This Source Code Form is subject to the terms of the JCZ-Automatisering License, v1.0. */
/* For more information, see the LICENSE file in the toplevel directory of this archive or package. */
/* Copyright 2020 - JCZ-Automatisering */

#include "config_value.h"

namespace jczconfig
{
    /**
     * @brief ConfigValue
     * @return
     */
    std::string ConfigValue::to_string(void) const
    {
        return key + "=" + value;
    }
}
