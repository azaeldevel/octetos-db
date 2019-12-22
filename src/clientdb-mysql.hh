#ifndef TOOLKIT_CLIENTDB_MYSQL_HPP
#define TOOLKIT_CLIENTDB_MYSQL_HPP

#include <vector>

#include "clientdb.hh"

namespace octetos
{
namespace db
{       
namespace mysql
{
        
	core::Version getPakageVersion();
	std::string getPakageName();	
        
        class Datconnect : public db::Datconnect
        {
        public:         
            Datconnect(const std::string& host, unsigned int port,const std::string& database,const std::string& usuario,const std::string& password);
            Datconnect(const Datconnect& obj);
            const Datconnect& operator=(const Datconnect&);
            ~Datconnect();
            Datconnect();
        };      

        class Row : public db::Row
        {
        public:
#ifdef COLLETION_ASSISTANT
                Row(Datresult* rs,void* row);
#endif
                virtual const char* operator[](unsigned long long index); 
                Row();
                virtual ~Row();
                Row(void* row);
                Row(Row& row);
        };
        
        class Datresult : public db::Datresult
        {
        public:
                virtual ~Datresult();
                Datresult(void* result);
                virtual db::Row* operator[](unsigned long long index);                
                virtual db::Row* next();
        };
        
        class Connector : public db::Connector
        {
        public:
            virtual ~Connector();
            Connector();
            virtual bool connect(const db::Datconnect* connector);
            const char* serverDescription();
            //virtual bool query(const std::string&);
            //virtual bool query(const std::string&, std::vector<std::vector<const char*>>&);
            virtual db::Datresult* query(const char*);
            virtual unsigned long long insert(const std::string&);
            virtual bool commit();
            virtual bool begin();
            virtual bool rollback();
            virtual void close();
        };      
}
}
}

#endif
