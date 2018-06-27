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
 * \file      get_configuration_file_path.cc
 * \brief     get_configuration_file_path function test
 * \copyright GNU Public License.
 * \author    Gabriele Labita
 *            <gabriele.labita@linux.it>
 *
 * This file contains test suite for the get_configuration_file_path
 * function.
 */

#include <string>
#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "../../src/configuration.hh"


TEST_GROUP(GetConfigurationFilePathTest) {
    void setup() { }
    void teardown() {
        mock().clear();
    }
};

/**
 * Expect configuration file to be CONFIGURATION_FILE_NAME in home
 * folder.
 */
TEST(GetConfigurationFilePathTest, Test_01) {
    std::string config = getenv(openair::HOME_ENV.c_str());
    config = config + "/" + openair::CONFIGURATION_FILE_NAME;
    CHECK_EQUAL(openair::get_configuration_file_path(), config);
}
