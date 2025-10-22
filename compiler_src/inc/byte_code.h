#ifndef BYTE_CODE_H
#define BYTE_CODE_H

#include <fstream>
#include <string>

namespace ByteCode
{
void iload (std::string, std::ofstream *);
void istore (std::string, std::ofstream *);
void iop (std::string, std::ofstream *);
void invokevirtual (std::string, std::ofstream *);
void ireturn (std::ofstream *);
void igoto (std::string, std::ofstream *);
void iffalse (std::string, std::ofstream *);
void iprint (std::ofstream *);
}

#endif // !BYTE_CODE_H
