/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.cc
 * Copyright (C) 2019 Azael R. <azael.devel@gmail.com>
 * 
 * octetos-db is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * octetos-db is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

//#include <iostream>
//#include "clientdb-mysql.hh"
//#include "clientdb-dbi.hh"

#include <CUnit/Basic.h>
#include <iostream>
#include <cstdlib>


#include "clientdb-mysql.hh"
#include "config.h"



static int majorNumber;


int init(void)
{
	return 0;
}

/* The suite cleanup function.
 * Closes the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int clean(void)
{
	return 0;
}


void testMySQL()
{
	///MySQL
	octetos::db::mysql::Datconnect dat("192.168.0.101",3306,"sysappv2.alpha","develop","123456");
	bool flag = false;
	octetos::db::mysql::Connector connector;
    try
    {
		flag = connector.connect(&dat);
	}
	catch(octetos::db::SQLException& ex)
	{
		std::cerr<<ex.what()<< std::endl;
		CU_ASSERT(false);
	}
    if(flag)
    {
        //printf("Version del Servidor  %s\n", connector.getVerionServer().toString().c_str());
		CU_ASSERT(true);
    }
    else
    {
        //printf("Fallo '%s' .\n",dat.toString().c_str());
		CU_ASSERT(false);
    }

	std::string query = "select * from Persons";
	octetos::db::Datresult* rs = connector.query(query.c_str());
	while(rs->nextRow())
	{
		octetos::db::Row* row = rs->getRow();
		//std::cout << row->getString(1) << "\n";
		delete row;
	}

	delete rs;

	///DBI
	/*
	octetos::db::dbi::Datconnect dat(octetos::db::Driver::MySQL,"192.168.0.101",3306,"sysappv2.alpha","develop","123456");
	bool flag = false;
	octetos::db::dbi::Connector connector;
    try
    {
		flag = connector.connect(&dat);
	}
	catch(octetos::db::SQLException& ex)
	{
		std::cerr<<ex.what()<< std::endl;
		return EXIT_FAILURE;
	}
    if(flag)
    {
        printf("Version del Servidor  %s\n", connector.getVerionServer().toString().c_str());
    }
    else
    {
        printf("Fallo '%s' .\n",dat.toString().c_str());

		return EXIT_FAILURE;
    }

	std::string query = "select * from Persons";
	octetos::db::Datresult* rs = connector.query(query.c_str());
	while(rs->nextRow())
	{
		std::cout << rs->getll(0) << "\n";
	}
	delete rs;
	*/


	
}


int main(int argc, char *argv[])
{;
	//octetos::core::Artifact packinfo = octetos::db::getPackageInfo();
    
	CU_pSuite pSuite = NULL;
	//majorNumber = packinfo.version.getMajor();
	/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

	//std::string classVersionString = packinfo.name + " " + packinfo.version.toString() + "\n" + packinfo.licence.getBrief() + "\n" + packinfo.brief + "\n";
	pSuite = CU_add_suite("Test", init, clean);
	if (NULL == pSuite) 
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
		
	if ((NULL == CU_add_test(pSuite, "Pruebas de MySQL", testMySQL)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	/* Run all tests using the CUnit Basic interface */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();	
}
