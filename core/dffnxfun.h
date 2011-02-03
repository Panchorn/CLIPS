   /*******************************************************/
   /*      "C" Language Integrated Production System      */
   /*                                                     */
   /*             CLIPS Version 6.24  06/05/06            */
   /*                                                     */
   /*              DEFFUNCTION HEADER FILE                */
   /*******************************************************/

/*************************************************************/
/* Purpose:                                                  */
/*                                                           */
/* Principal Programmer(s):                                  */
/*      Brian L. Dantes                                      */
/*      Gary D. Riley                                        */
/*                                                           */
/* Contributing Programmer(s):                               */
/*                                                           */
/* Revision History:                                         */
/*      6.23: Corrected compilation errors for files         */
/*            generated by constructs-to-c. DR0861           */
/*                                                           */
/*      6.24: Renamed BOOLEAN macro type to intBool.         */
/*                                                           */
/*************************************************************/

#ifndef _H_dffnxfun
#define _H_dffnxfun

#define EnvGetDeffunctionName(theEnv,execStatus,x) GetConstructNameString((struct constructHeader *) x)
#define EnvGetDeffunctionPPForm(theEnv,execStatus,x) GetConstructPPForm(theEnv,execStatus,(struct constructHeader *) x)

#define GetDeffunctionNamePointer(x) GetConstructNamePointer((struct constructHeader *) x)
#define SetDeffunctionPPForm(d,ppf) SetConstructPPForm(theEnv,execStatus,(struct constructHeader *) d,ppf)

#define EnvDeffunctionModule(theEnv,execStatus,x) GetConstructModuleName((struct constructHeader *) x)

typedef struct deffunctionStruct DEFFUNCTION;
typedef struct deffunctionModule DEFFUNCTION_MODULE;

#ifndef _H_conscomp
#include "conscomp.h"
#endif
#ifndef _H_cstrccom
#include "cstrccom.h"
#endif
#ifndef _H_moduldef
#include "moduldef.h"
#endif
#ifndef _H_evaluatn
#include "evaluatn.h"
#endif
#ifndef _H_expressn
#include "expressn.h"
#endif
#ifndef _H_symbol
#include "symbol.h"
#endif

#ifdef LOCALE
#undef LOCALE
#endif
#ifdef _DFFNXFUN_SOURCE_
#define LOCALE
#else
#define LOCALE extern
#endif

struct deffunctionModule
  {
   struct defmoduleItemHeader header;
  };

struct deffunctionStruct
  {
   struct constructHeader header;
   unsigned busy,
            executing;
   unsigned short trace;
   EXPRESSION *code;
   int minNumberOfParameters,
       maxNumberOfParameters,
       numberOfLocalVars;
  };
  
#define DEFFUNCTION_DATA 23

struct deffunctionData
  { 
   struct construct *DeffunctionConstruct;
   int DeffunctionModuleIndex;
   ENTITY_RECORD DeffunctionEntityRecord;
#if DEBUGGING_FUNCTIONS
   unsigned WatchDeffunctions;
#endif
   struct CodeGeneratorItem *DeffunctionCodeItem;
   DEFFUNCTION *ExecutingDeffunction;
#if (! BLOAD_ONLY) && (! RUN_TIME)
   struct token DFInputToken;
#endif
  };

#define DeffunctionData(theEnv,execStatus) ((struct deffunctionData *) GetEnvironmentData(theEnv,execStatus,DEFFUNCTION_DATA))

#define DeffunctionModule(x) GetConstructModuleName((struct constructHeader *) x)
#define FindDeffunction(a) EnvFindDeffunction(GetCurrentEnvironment(),GetCurrentExecutionStatus(),a)
#define GetDeffunctionList(a,b) EnvGetDeffunctionList(GetCurrentEnvironment(),GetCurrentExecutionStatus(),a,b)
#define GetDeffunctionName(x) GetConstructNameString((struct constructHeader *) x)
#define GetDeffunctionPPForm(x) GetConstructPPForm(GetCurrentEnvironment(),GetCurrentExecutionStatus(),(struct constructHeader *) x)
#define GetDeffunctionWatch(a) EnvGetDeffunctionWatch(GetCurrentEnvironment(),GetCurrentExecutionStatus(),a)
#define GetNextDeffunction(a) EnvGetNextDeffunction(GetCurrentEnvironment(),GetCurrentExecutionStatus(),a)
#define IsDeffunctionDeletable(a) EnvIsDeffunctionDeletable(GetCurrentEnvironment(),GetCurrentExecutionStatus(),a)
#define ListDeffunctions(a,b) EnvListDeffunctions(GetCurrentEnvironment(),GetCurrentExecutionStatus(),a,b)
#define SetDeffunctionWatch(a,b) EnvSetDeffunctionWatch(GetCurrentEnvironment(),GetCurrentExecutionStatus(),a,b)
#define Undeffunction(a) EnvUndeffunction(GetCurrentEnvironment(),GetCurrentExecutionStatus(),a)

LOCALE void SetupDeffunctions(void *,EXEC_STATUS);
LOCALE void *EnvFindDeffunction(void *,EXEC_STATUS,char *);
LOCALE DEFFUNCTION *LookupDeffunctionByMdlOrScope(void *,EXEC_STATUS,char *);
LOCALE DEFFUNCTION *LookupDeffunctionInScope(void *,EXEC_STATUS,char *);
LOCALE intBool EnvUndeffunction(void *,EXEC_STATUS,void *);
LOCALE void *EnvGetNextDeffunction(void *,EXEC_STATUS,void *);
LOCALE int EnvIsDeffunctionDeletable(void *,EXEC_STATUS,void *);
LOCALE void UndeffunctionCommand(void *,EXEC_STATUS);
LOCALE void *GetDeffunctionModuleCommand(void *,EXEC_STATUS);
LOCALE void DeffunctionGetBind(DATA_OBJECT *);
LOCALE void DFRtnUnknown(DATA_OBJECT *);
LOCALE void DFWildargs(DATA_OBJECT *);
LOCALE int CheckDeffunctionCall(void *,EXEC_STATUS,void *,int);
#if DEBUGGING_FUNCTIONS
LOCALE void PPDeffunctionCommand(void *,EXEC_STATUS);
LOCALE void ListDeffunctionsCommand(void *,EXEC_STATUS);
LOCALE void EnvListDeffunctions(void *,EXEC_STATUS,char *,struct defmodule *);
LOCALE void EnvSetDeffunctionWatch(void *,EXEC_STATUS,unsigned,void *);
LOCALE unsigned EnvGetDeffunctionWatch(void *,EXEC_STATUS,void *);
#endif
#if (! BLOAD_ONLY) && (! RUN_TIME)
LOCALE void RemoveDeffunction(void *,EXEC_STATUS,void *);
#endif

LOCALE void GetDeffunctionListFunction(void *,EXEC_STATUS,DATA_OBJECT *);
globle void EnvGetDeffunctionList(void *,EXEC_STATUS,DATA_OBJECT *,struct defmodule *);

#endif






