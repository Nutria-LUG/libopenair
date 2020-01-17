/* libopenair - Library containing openair system's component. 
 * Copyright (C) 2018 Gabriele Labita
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/*!
 * \file      configuration/configuration_keys.cc
 * \brief     Test for configuration keys
 * \copyright GNU Public License.
 * \author    Gabriele Labita
 *            <gabriele.labita@linux.it>
 *
 * This file defines the test to check the configuaration key values.
 */

#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "../../src/libopenair/configuration.hh"

TEST_GROUP(ConfigurationKeys) {
    void setup() { }
    void teardown() {
        mock().clear();
    }
};

/**
 * Expect CONFIGUARTION_FILE_NAME to be ".openair.conf"
 */
TEST(ConfigurationKeys, Test_01) {
    CHECK_EQUAL(openair::CONFIGURATION_FILE_NAME,
                ".openair.conf");
}

/**
 * Expect HOME_ENV to be "HOME"
 */
TEST(ConfigurationKeys, Test_03) {
    CHECK_EQUAL(openair::HOME_ENV, "HOME");
}

/**
 * Expect DATABASE_PATH_KEY to be "data_base_path"
 */
TEST(ConfigurationKeys, Test_04) {
    CHECK_EQUAL(openair::DATABASE_PATH_KEY,
                "data_base_path");
}

/**
 * Expect SERVICE_ADDRESS_KEY to be "service_address"
 */
TEST(ConfigurationKeys, Test_05) {
    CHECK_EQUAL(openair::SERVICE_ADDRESS_KEY,
                "service_address");
}

/**
 * Expect VPN_REGISTRATION_METHOD_KEY to be "vpn_registration_method"
 */
TEST(ConfigurationKeys, Test_06) {
    CHECK_EQUAL(openair::VPN_REGISTRATION_METHOD_KEY,
                "vpn_registration_method");
}


/**
 * Expect SEND_DATA_METHOD_KEY to be "send_data_method"
 */
TEST(ConfigurationKeys, Test_07) {
    CHECK_EQUAL(openair::SEND_DATA_METHOD_KEY,
                "send_data_method");
}

/**
 * Expect SEND_ERRORS_METHOD_KEY to be "send_errors_method"
 */
TEST(ConfigurationKeys, Test_08) {
    CHECK_EQUAL(openair::SEND_ERRORS_METHOD_KEY,
                "send_errors_method");
}
