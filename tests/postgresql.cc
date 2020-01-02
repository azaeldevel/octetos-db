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


#include "clientdb-postgresql.hh"
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


void testConnection()
{
	///MySQL
	octetos::db::postgresql::Datconnect dat("192.168.0.101",5432,"sysapp_v0001","sysapp","123456");
	bool flag = false;
	octetos::db::postgresql::Connector connector;
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

	/*std::string queryStr = "select * from Persons";
	octetos::db::Datresult* rs = connector.query(queryStr.c_str());
	while(rs->nextRow())
	{
		std::cout << rs->getString(1) << "\n";
	}

	delete rs;
	connector.close();*/
	
}


int main(int argc, char *argv[])
{
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
		
	if ((NULL == CU_add_test(pSuite, "Pruebas de Conexcion PostgreSQL", testConnection)))
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

