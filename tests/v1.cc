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


#include <CUnit/Basic.h>
#include <iostream>
#include <cstdlib>

#include "config.h"

#ifdef OCTETOS_POSTGRESQL
	#include "clientdb-postgresql.hh"
#endif
#ifdef OCTETOS_MYSQL
	#include "clientdb-mysql.hh"
#endif
#ifdef OCTETOS_MARIADB
	#include "clientdb-maria.hh"
#endif

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

#ifdef OCTETOS_POSTGRESQL
void testPostgreSQL()
{
	//std::cout << "testPostgreSQL : Step 1 \n";
	octetos::db::postgresql::Datconnect dat("localhost",5432,"sysapp_alpha","sysapp","123456");
	bool flag = false;
	octetos::db::postgresql::Connector connector;
	flag = connector.connect(dat);
    if(flag)
    {
        //printf("Version del Servidor  %s\n", connector.getVerionServer().toString().c_str());
		CU_ASSERT(true);
    }
    else
    {
        printf("Fallo '%s' .\n",dat.toString().c_str());
		CU_ASSERT(false);
    }

	octetos::db::postgresql::Datresult rsInsert;
	std::string insertStr = "INSERT INTO \"Persons\"(name1) values('n1')";
	octetos::db::RowNumber id = 0;
	try
	{
		id = connector.insert(insertStr,rsInsert);
	}
	catch(octetos::db::SQLException e)
	{
		std::cout << "Fallo en insert '" << insertStr << "'\n";
		CU_ASSERT(false);
	}
	//connector.commit ();
	
	//std::cout << "ID generated : " << id << "\n";
	CU_ASSERT(true);


	std::string queryStr = "select * from \"Persons\"";
	octetos::db::postgresql::Datresult rs;
	if(!connector.execute(queryStr,rs))
	{
		if(octetos::core::Error::check())
		{
			std::cout << "Error: " << octetos::core::Error::get().describe();
		}
		CU_ASSERT(false);
		return;
	}
	std::cout << "\n\n";
	while(rs.nextRow())
	{
		std::cout << rs.getString(0) << "," << rs.getString(1) << "\n";
	}

	connector.close();
}

#endif

#ifdef OCTETOS_MYSQL
void testMySQL()
{
	///MySQL
	octetos::db::mysql::Datconnect dat("192.168.0.101",3306,"sysappv2.alpha","develop","123456");
	bool flag = false;
	octetos::db::mysql::Connector connector;
	flag = connector.connect(dat);
    if(flag)
    {
        //printf("Version del Servidor  %s\n", connector.getVerionServer().toString().c_str());
		CU_ASSERT(true);
    }
    else
    {
        printf("Fallo '%s' .\n",dat.toString().c_str());
		CU_ASSERT(false);
		return;
    }

	std::string queryStr = "select * from Persons";
	octetos::db::mysql::Datresult rs;
	connector.execute(queryStr,rs);
	while(rs.nextRow())
	{
		//std::cout << rs->getString(1) << "\n";
	}
	
	connector.close();
}
#endif
#ifdef OCTETOS_MARIADB
void testMariaDB()
{
	///MySQL
	octetos::db::mariadb::Datconnect dat("192.168.0.101",3306,"sysappv2.alpha","develop","123456");
	bool flag = false;
	octetos::db::mariadb::Connector connector;
	flag = connector.connect(dat);
    if(flag)
    {
        //printf("Version del Servidor  %s\n", connector.getVerionServer().toString().c_str());
		CU_ASSERT(true);
    }
    else
    {
        printf("Fallo '%s' .\n",dat.toString().c_str());
		CU_ASSERT(false);
		return;
    }

	std::string queryStr = "select * from Persons";
	octetos::db::mariadb::Datresult rs;
	connector.execute(queryStr,rs);
	while(rs.nextRow())
	{
		//std::cout << rs->getString(1) << "\n";
	}
	
	connector.close();
}
#endif

void testOperations()
{
	//octetos::db::Datconnect dat(octetos::db::Driver::MariaDB,"192.168.0.101",3306,"sysappv2.alpha","develop","123456");
	
	/*octetos::core::Artifact packinfo;	
	octetos::db::getPackageInfo(packinfo);
	time_t seconds = time (NULL);
	std::string str = std::to_string(seconds);
	std::string filename = packinfo.name;
	filename += "-" + str + ".cfg"; 
	if(dat.write(filename))
	{
		CU_ASSERT(true);
	}
	else
	{
		CU_ASSERT(false);
	}*/
}

int main(int argc, char *argv[])
{
	bool run_mysql = false, run_postgresql = false, run_mariadb = false;
	
	octetos::core::Artifact packinfo;
	octetos::db::getPackageInfo(packinfo);
	
	int majorDevelop = 1;
	if(majorDevelop != packinfo.version.getMajor())
	{
		std::cerr << "Este conjunto de pruebas estan Deseñado para la version mayor '" << majorDevelop << "'(" << (std::string)packinfo.version << ")\n";
		return EXIT_FAILURE;
	}
	
	for(int i = 1;i < argc; i++)
	{
		if(strcmp(argv[i],"--run-mysql") == 0)
		{
			run_mysql = true;
		}
		else if(strcmp(argv[i],"--run-postgresql") == 0)
		{
			run_postgresql = true;
		}
		else if(strcmp(argv[i],"--run-mariadb") == 0)
		{
			run_mariadb = true;
		}
	}
    
	CU_pSuite pSuite = NULL;
	if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

	
	std::string& pkName = packinfo.name;
	std::string headerTest = pkName + " " + (std::string)packinfo.version + "\n" + packinfo.licence.getText() + "\n" + packinfo.brief + "\n";
	pSuite = CU_add_suite(headerTest.c_str(), init, clean);
	if (NULL == pSuite) 
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
#ifdef OCTETOS_MYSQL	
	if(run_mysql)
	{
		if ((NULL == CU_add_test(pSuite, "Ejecucion MySQL", testMySQL)))
		{
			CU_cleanup_registry();
			return CU_get_error();
		}
	}
#endif
#ifdef OCTETOS_POSTGRESQL	
	if(run_postgresql)
	{
		if ((NULL == CU_add_test(pSuite, "Ejecucion de PostgreSQL", testPostgreSQL)))
		{
			CU_cleanup_registry();
			return CU_get_error();
		}
	}
#endif
#ifdef OCTETOS_MARIADB	
	if(run_mariadb)
	{
		if ((NULL == CU_add_test(pSuite, "Ejecucion de MariaDB", testMariaDB)))
		{
			CU_cleanup_registry();
			return CU_get_error();
		}
	}
#endif
	
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}

