
#if defined(__linux__)

#elif defined(_WIN32) || defined(_WIN64)

#else
    #error "Plataforma desconocida"
#endif

#include "clientdb.hh"

namespace octetos
{
namespace db
{
	int inet_pton(int af, const char *src, char *dst);
	int inet_pton4(const char *src, char *dst);
	int inet_pton6(const char *src, char *dst);
}
}
