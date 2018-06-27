#include "./configuration/configuration_keys.cc"
#include "./configuration/operators_overload.cc"
#include "./configuration/get_configuration_file_path.cc"
#include "CppUTest/CommandLineTestRunner.h"

int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}
