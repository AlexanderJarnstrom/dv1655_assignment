/**
 * @file
 * @brief Functions writing corresponding byte code to the file.
 */

#ifndef BYTE_CODE_H
#define BYTE_CODE_H

#include <fstream>
#include <string>

namespace ByteCode
{
void iload(std::string target, std::ofstream* out);
void istore(std::string target, std::ofstream* out);
void iop(std::string op, std::ofstream* out);
void invokevirtual(std::string target, std::ofstream* out);
void ireturn(std::ofstream* out);
void igoto(std::string target, std::ofstream* out);
void iffalse(std::string target, std::ofstream* out);
void iprint(std::ofstream* out);
}  // namespace ByteCode

#endif  // !BYTE_CODE_H
