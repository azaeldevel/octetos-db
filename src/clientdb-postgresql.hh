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

    
	class Datresult : public db::Datresult
	{
	private:		
		unsigned long long currentRow;
                
	public:
		Datresult(void* result);
		virtual ~Datresult();
		virtual bool nextRow();
		void* getResult() const;
		//retrive data field by index
		virtual char getchar(IndexField field)const;
		virtual unsigned char getuchar(IndexField field)const;
		virtual short getshort(IndexField field)const;
		virtual unsigned short getushort(IndexField field)const;
		virtual int getint(IndexField field)const;
		virtual unsigned int getuint(IndexField field)const;
		virtual long getl(IndexField field)const;
		virtual unsigned long getul(IndexField field)const;
		virtual long long getll(IndexField field)const;
		virtual unsigned long long getull(IndexField field)const;
		virtual float getfloat(IndexField field)const;
		virtual double getdouble(IndexField field)const;
		virtual std::string getString(IndexField field)const;
		//retrive data field by name
		virtual char getchar(const std::string&)const;
		virtual unsigned char getuchar(const std::string&)const;
		virtual short getshort(const std::string&)const;
		virtual unsigned short getushort(const std::string&)const;
		virtual int getint(const std::string&)const;
		virtual unsigned int getuint(const std::string&)const;
		virtual long getl(const std::string&)const;
		virtual unsigned long getul(const std::string&)const;
		virtual long long getll(const std::string&)const;
		virtual unsigned long long getull(const std::string&)const;
		virtual float getfloat(const std::string&)const;
		virtual double getdouble(const std::string&)const;
		virtual std::string getString(const std::string&)const;
		//retrive field meta-data
		virtual size_t getFieldLength(db::IndexField field) const;
		virtual size_t getFieldLength(const std::string&) const;
		virtual IndexField getFieldNumbers() const;
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
