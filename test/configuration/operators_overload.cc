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
 * \file      configuration/operators_overalod.cc
 * \brief     Test the ConfigurationData overaload operator.
 * \copyright GNU Public License.
 * \author    Gabriele Labita
 *            <gabriele.labita@linux.it>
 *
 * This file contains test suite for the overloading for the
 * ConfigurationData struct.
 */

#include <sstream>
#include <string>
#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "../../src/configuration.hh"

inline SimpleString StringFrom(
    const openair::ConfigurationData& config) {
    std::stringstream ss;
    ss << config;
    return ss.str().c_str();
}

TEST_GROUP(OverloadOperators) {
    void setup() { }
    void teardown() {
        mock().clear();
    }
};

/**
 * HAVE An empty stream
 * WHEN put that stream in ConfigruationData struct
 * THEN nothing to be done and struct has its default values.
 */
TEST(OverloadOperators, Test_01) {
    openair::ConfigurationData to_input;
    openair::ConfigurationData default_struct;
    
    CHECK_EQUAL(to_input, default_struct);
}

/**
 * HAVE A stream with database_path defined 
 * WHEN use operator>> in a ConfigurationData object
 * THEN database_path attribute to be equals to the one on the
 *      stream.
 */
TEST(OverloadOperators, Test_02) {
    std::stringstream ss;
    std::string database_path = "./path/to/the/database.db";
    ss << openair::DATABASE_PATH_KEY << " = " << database_path;
    openair::ConfigurationData config;
    ss >> config;
    CHECK_EQUAL(config.database_path, database_path);
}

/**
 * HAVE A stream with service address defined 
 * WHEN use operator>> in a ConfigurationData object
 * THEN service_address attribute to be equals to the one on the
 *      stream.
 */
TEST(OverloadOperators, Test_03) {
    std::stringstream ss;
    std::string service_address = "https://service.address.com";
    ss << openair::SERVICE_ADDRESS_KEY << " = " <<service_address;
    openair::ConfigurationData config;
    ss >> config;
    CHECK_EQUAL(config.service_address, service_address);
}

/**
 * HAVE A stream with vpn registration meethod defined 
 * WHEN use operator>> in a ConfigurationData object
 * THEN vpn_registration_method attribute to be equals to the one on
 *      the stream.
 */
TEST(OverloadOperators, Test_04) {
    std::stringstream ss;
    std::string method = "vpn/registration/method";
    ss << openair::VPN_REGISTRATION_METHOD_KEY << " = " << method;
    openair::ConfigurationData config;
    ss >> config;
    CHECK_EQUAL(config.vpn_registration_method, method);
}

/**
 * HAVE A stream with send data method defined 
 * WHEN use operator>> in a ConfigurationData object
 * THEN send_data_method attribute to be equals to the one on
 *      the stream.
 */
TEST(OverloadOperators, Test_05) {
    std::stringstream ss;
    std::string method = "send/data/method";
    ss << openair::SEND_DATA_METHOD_KEY << " = " << method;
    openair::ConfigurationData config;
    ss >> config;
    CHECK_EQUAL(config.send_data_method, method);
}

/**
 * HAVE A stream with send errors method defined 
 * WHEN use operator>> in a ConfigurationData object
 * THEN send_errors_method attribute to be equals to the one on
 *      the stream.
 */
TEST(OverloadOperators, Test_06) {
    std::stringstream ss;
    std::string method = "send/erros/method";
    ss << openair::SEND_ERRORS_METHOD_KEY << " = " << method;
    openair::ConfigurationData config;
    ss >> config;
    CHECK_EQUAL(config.send_errors_method, method);
}

/**
 * HAVE A stream with some keys defined separated by \n
 * WHEN use operator>> in a ConfigurationData object
 * THEN that keys to have been set in the relative methods (see
 *      test from 2 to 6).
 */
TEST(OverloadOperators, Test_07) {
    std::stringstream ss;
    ss << openair::DATABASE_PATH_KEY << " = " << "a" << "\n"
       << openair::SERVICE_ADDRESS_KEY << " = " << "b" << "\n"
       << openair::VPN_REGISTRATION_METHOD_KEY << " = " << "c" << "\n"
       << openair::SEND_DATA_METHOD_KEY << " = " << "d" << "\n"
       << openair::SEND_ERRORS_METHOD_KEY << " = " << "e" << "\n";
    openair::ConfigurationData config;
    ss >> config;
    CHECK_EQUAL(config.database_path, "a");
    CHECK_EQUAL(config.service_address, "b");
    CHECK_EQUAL(config.vpn_registration_method, "c");
    CHECK_EQUAL(config.send_data_method, "d");
    CHECK_EQUAL(config.send_errors_method, "e");
}


/**
 * HAVE A new ConfigurationData
 * WHEN print it through operator<<
 * THEN string printed contains all default values.
 */
TEST(OverloadOperators, Test_08) {
    openair::ConfigurationData config;
    std::string expected =
        openair::DATABASE_PATH_KEY + "=\n" +
        openair::SERVICE_ADDRESS_KEY + "=\n" +
        openair::VPN_REGISTRATION_METHOD_KEY + "=\n" +
        openair::SEND_DATA_METHOD_KEY + "=\n" +
        openair::SEND_ERRORS_METHOD_KEY + "=\n";
    std::stringstream ss;
    ss <<  config;
    CHECK_EQUAL(ss.str(), expected);
}

/**
 * HAVE A new ConfigurationData with data base path set
 * WHEN print it through operator<<
 * THEN string printed contains the right value.
 */
TEST(OverloadOperators, Test_09) {
    openair::ConfigurationData config;
    config.database_path = "data_base.db";
    std::string expected =
        openair::DATABASE_PATH_KEY + "=data_base.db\n" +
        openair::SERVICE_ADDRESS_KEY + "=\n" +
        openair::VPN_REGISTRATION_METHOD_KEY + "=\n" +
        openair::SEND_DATA_METHOD_KEY + "=\n" +
        openair::SEND_ERRORS_METHOD_KEY + "=\n";
    std::stringstream ss;
    ss <<  config;
    CHECK_EQUAL(ss.str(), expected);
}


/**
 * HAVE A new ConfigurationData with all attribute set
 * WHEN print it through operator<<
 * THEN string printed contains the right values.
 */
TEST(OverloadOperators, Test_10) {
    openair::ConfigurationData config;
    config.database_path = "data_base.db";
    config.service_address = "serviceaddress";
    config.vpn_registration_method = "regmethod";
    config.send_data_method = "senddata";
    config.send_errors_method = "senderrors";
    
    std::string expected =
        openair::DATABASE_PATH_KEY + "=data_base.db\n" +
        openair::SERVICE_ADDRESS_KEY + "=serviceaddress\n" +
        openair::VPN_REGISTRATION_METHOD_KEY + "=regmethod\n" +
        openair::SEND_DATA_METHOD_KEY + "=senddata\n" +
        openair::SEND_ERRORS_METHOD_KEY + "=senderrors\n";
    std::stringstream ss;
    ss <<  config;
    CHECK_EQUAL(ss.str(), expected);
}


/**
 * HAVE Two new configuration data
 * WHEN compare theme through operator==
 * THEN they are equals
 */
TEST(OverloadOperators, Test_11) {
    openair::ConfigurationData config1;
    openair::ConfigurationData config2;    
    CHECK(config1 == config2);
}


/**
 * HAVE Two configuration data with same attributes
 * WHEN compare theme through operator==
 * THEN they are equals
 */
TEST(OverloadOperators, Test_12) {
    openair::ConfigurationData config1;
    openair::ConfigurationData config2;
    config1.database_path = "a";
    config1.service_address = "b";
    config1.vpn_registration_method = "c";
    config1.send_data_method = "d";
    config1.send_errors_method = "e";

    config2.database_path = "a";
    config2.service_address = "b";
    config2.vpn_registration_method = "c";
    config2.send_data_method = "d";
    config2.send_errors_method = "e";
    
    CHECK(config1 == config2);
}


/**
 * HAVE Two configuration data with a different attribute
 * WHEN compare theme through operator==
 * THEN they are not equals
 */
TEST(OverloadOperators, Test_13) {
    openair::ConfigurationData config1;
    openair::ConfigurationData config2;
    config1.database_path = "a";
    config1.service_address = "b";
    config1.vpn_registration_method = "c";
    config1.send_data_method = "d";
    config1.send_errors_method = "e";

    config2.database_path = "a";
    config2.service_address = "b";
    config2.vpn_registration_method = "c";
    config2.send_data_method = "d";
    config2.send_errors_method = "42";
    
    CHECK(!(config1 == config2));
}

/**
 * HAVE Two new configuration data
 * WHEN compare theme through operator!=
 * THEN they are equals
 */
TEST(OverloadOperators, Test_14) {
    openair::ConfigurationData config1;
    openair::ConfigurationData config2;    
    CHECK(!(config1 != config2));
}


/**
 * HAVE Two configuration data with same attributes
 * WHEN compare theme through operator1=
 * THEN they are not equals
 */
TEST(OverloadOperators, Test_15) {
    openair::ConfigurationData config1;
    openair::ConfigurationData config2;
    config1.database_path = "a";
    config1.service_address = "b";
    config1.vpn_registration_method = "c";
    config1.send_data_method = "d";
    config1.send_errors_method = "e";

    config2.database_path = "a";
    config2.service_address = "b";
    config2.vpn_registration_method = "c";
    config2.send_data_method = "d";
    config2.send_errors_method = "e";
    
    CHECK(!(config1 != config2));
}


/**
 * HAVE Two configuration data with a different attribute
 * WHEN compare theme through operator!=
 * THEN they are not equals
 */
TEST(OverloadOperators, Test_16) {
    openair::ConfigurationData config1;
    openair::ConfigurationData config2;
    config1.database_path = "a";
    config1.service_address = "b";
    config1.vpn_registration_method = "c";
    config1.send_data_method = "d";
    config1.send_errors_method = "e";

    config2.database_path = "a";
    config2.service_address = "b";
    config2.vpn_registration_method = "c";
    config2.send_data_method = "d";
    config2.send_errors_method = "42";
    
    CHECK(config1 != config2);
}
