/*
 * sources.h: Source handling
 *
 * See the main source file 'vdr.c' for copyright information and
 * how to reach the author.
 *
 * $Id: sources.h 2.1 2010/02/21 16:11:19 kls Exp $
 */

#ifndef __SOURCES_H
#define __SOURCES_H

#include "config.h"

class cSource : public cListObject {
public:
  enum eSourceType {
    stNone  = 0x00000000,
    stCable = ('C' << 24),
    stSat   = ('S' << 24),
    stTerr  = ('T' << 24),
    st_Mask = 0xFF000000,
    st_Pos  = 0x0000FFFF,
    };
private:
  int code;
  char *description;
public:
  cSource(void);
  cSource(char Source, const char *Description);
  ~cSource();
  int Code(void) const { return code; }
  const char *Description(void) const { return description; }
  bool Parse(const char *s);
  static cString ToString(int Code);
  static int FromString(const char *s);
  static int FromData(eSourceType SourceType, int Position = 0, bool East = false);
  static bool IsCable(int Code) { return (Code & st_Mask) == stCable; }
  static bool IsSat(int Code) { return (Code & st_Mask) == stSat; }
  static bool IsTerr(int Code) { return (Code & st_Mask) == stTerr; }
  };

class cSources : public cConfig<cSource> {
public:
  cSource *Get(int Code);
  };

extern cSources Sources;

#endif //__SOURCES_H
