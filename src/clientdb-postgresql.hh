#ifndef TOOLKIT_CLIENTDB_POSTGRESQL_HPP
#define TOOLKIT_CLIENTDB_POSTGRESQL_HPP

#include <vector>

#include "clientdb.hh"

namespace octetos
{
namespace db
{
namespace postgresql
{                   

        
        class Datconnect : public db::Datconnect
        {
        public:         
            Datconnect(const std::string& host, unsigned int port,const std::string& database,const std::string& usuario,const std::string& password);
            Datconnect(const Datconnect& obj);
            const Datconnect& operator=(const Datconnect&);
        };

        class Connector : public db::Connector
        {
        public:
            virtual ~Connector();
            Connector();
            const db::Datconnect& getDatconection() const; 
			//
            virtual bool connect(const db::Datconnect* connector);            
            virtual db::Datresult* query(const std::string& str);
            virtual unsigned long long insert(const std::string&);
            virtual bool commit();
            virtual bool begin();
            virtual bool rollback();
            virtual void close(); 
			virtual core::Semver getVerionServer() const;
        };
}
}
}
#endif
