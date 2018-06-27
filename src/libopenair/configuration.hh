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
 * \file      configuration.hh
 * \brief     This file contains the definition of the components and
 *            operators to fill the configuration structure.
 * \copyright GNU Public License.
 * \author    Gabriele Labita
 *            <gabriele.labita@linux.it>
 *
 * This contains the components definition used to fill the
 * configuration structure. Congiruation is loaded from config file (in
 * the home envirnomente) and loaded in memory in a data struct to be
 * used in the whole program.
 */

#include <string>
#include <iostream>

#ifndef CONFIGURATION_INCLUDE_GUARD_HH
#define CONFIGURATION_INCLUDE_GUARD_HH 1

namespace openair {

   /*! This is the name of the openair configuration file. */
    const std::string CONFIGURATION_FILE_NAME = ".openair.conf";

   /*!
    * This is the ENV code used to represent the home folder
    * in the current system (see getenv standard function).
    */
    const std::string HOME_ENV = "HOME";

     /*!
      * This represent the key value of the data base path in the
      * configuration file.
      */
    const std::string DATABASE_PATH_KEY = "data_base_path";

    /*!
     * This represent the key value of the service address.
     */
    const std::string SERVICE_ADDRESS_KEY = "service_address";

    /*!
     * This macro represent the key value of the method used to
     * register a client in the vpn.
     */
    const std::string VPN_REGISTRATION_METHOD_KEY =
        "vpn_registration_method";

    /*!
     * This macro represent the key value of the method used to send
     * data to the service
     */
    const std::string SEND_DATA_METHOD_KEY = "send_data_method";

    /*!
     * This macro represent the key value of the method used to send
     * errors to the service
     */
    const std::string SEND_ERRORS_METHOD_KEY = "send_errors_method";
        
    /*!
     * Data struct that contains the configuration informations.
     */
    struct ConfigurationData {
        /*! 
         * Sqlite3 data base path that contains the database where
         * perform the log operations.
         */
        std::string database_path;
        
        /*! Address of the remote service. */
        std::string service_address;

        /*!
         * Name of the method to call to register a client in the
         * vpn.
         */
        std::string vpn_registration_method;

        /*! Name of the method to call to send surveys data. */
        std::string send_data_method;

        /*! Name of the method to call to send errors. */
        std::string send_errors_method;
        
        /*! Default constructor. */
        ConfigurationData();
        
        /*! Default destructor. */
        ~ConfigurationData();
    };

    /*!
     * \brief Gets the configuration file path.
     *
     * This function return the configuration file path for the
     * openair system.
     * \return A string that represent the path of to the
     *         configuaration file. It is located in
     *         HOME\CONFIGURATION_FILE_NAME, where
     *         CONFIGURATION_FILE_NAME is the constant defined in
     *         this namespace and HOME is the path to the home
     *         directory.
     */
    std::string get_configuration_file_path();
}

/*!
 * \brief This is the operator>> overloading used to initialize the
 *        configuration.
 *
 * Configuration must be passed in the following format:
 *   key = value
 * Where:
 *  key:   Name of the field to configure
 *  value: Value of that field.
 * Each key value pair will be put in the config object passed as
 * parameter.
 * Characters: '#' and ';' are handled as comments.
 *
 * \param is     - Input stream used to initialize the
 *                  configuration object.
 * \param config - Configuration object to initialize.
 * \return istream object passed as parameter to allow chaining.
 */
std::istream& operator>>(std::istream& is,
                         openair::ConfigurationData& config);


/*!
 * \brief This is the operator<< overloading used to print the
 *        configuration
 *
 * Configuration is printed in the following format:
 *   key = value
 * Where:
 *  key:   Name of the field to configure
 *  value: Value of that field.
 *
 * \param os     - Output stream used to print the configuration
 *                 object.
 * \param config - Configuration object to print.
 * \return ostream object passed as parameter to allow chaining.
 */
std::ostream& operator<<(std::ostream& os,
                         const openair::ConfigurationData& config);
/*!
 * \brief operator== overloading.
 *
 * Check if the object passed as parameters are equals. They are
 * equals only if all their attributes are eqauls.
 *
 * \param a - First object to compare.
 * \param b - Second object to compare.
 * \return True if the two objects are equals, false otherwise.
 */
bool operator==(const openair::ConfigurationData& a,
                const openair::ConfigurationData& b);

/*!
 * \brief operator!= overloading.
 *
 * Check if the object passed as parameters are differents. They are
 * differents only if they are not equlas. This method uses operator==
 * overload.
 *
 * \param a - First object to compare.
 * \param b - Second object to compare.
 * \return True if the two objects are different, false otherwise.
 */
bool operator!=(const openair::ConfigurationData& a,
                const openair::ConfigurationData& b);
#endif
