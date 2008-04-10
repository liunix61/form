#ifndef __FDECLARE__

#define __FDECLARE__

/** @file declare.h
 *
 *  Contains macros and function declarations.
 */

/*
  	#[ ARG definitions :
*/

#ifdef ANSI
/**
 *	First the declaration macro's. They are to keep the code portable.
 *	They wouldn't be needed ordinarily, but there is such a thing as
 *	the "IBM interpretation of the ANSI standard".
 *	In the old days there was also the difference between K&R C and Ansi C.
 *	By using macro's for the definition of functions we ensure that we
 *	don't need all kinds of ifdef's for each function we define.
 *
 *	There are two types of macro's. The ones that are called ARG0, ARG1, ...
 *	and the ones that are called BARG0, BARG1, ...
 *	The last ones were introduced when TFORM was programmed. In the case of
 *	workers, each worker may need some private data. These can in principle
 *	be accessed by some posix calls but that is unnecessarily slow. The
 *	passing of a pointer to the complete data struct with private data will
 *	be much faster. And anyway, there would have to be a macro that either
 *	makes the posix call (TFORM) or doesn't (FORM). The solution by having
 *	macro's that either pass the pointer (TFORM) or don't pass it (FORM)
 *	is seen as the best solution.
 *
 *	In the declarations and the calling of the functions we have to use
 *	either the PHEAD or the BHEAD macro if the pointer is to be passed.
 *	These macro's contain the comma as well. Hence we need special macro's
 *	if there are no other arguments. These are called PHEAD0 and BHEAD0.
 */

#ifdef INTELCOMPILER
#define ARG0 ()
#else
#define ARG0 (VOID)
#endif
#define ARG1(x1,y1) (x1 y1)
#define ARG2(x1,y1,x2,y2) (x1 y1,x2 y2)
#define ARG3(x1,y1,x2,y2,x3,y3) (x1 y1,x2 y2,x3 y3)
#define ARG4(x1,y1,x2,y2,x3,y3,x4,y4) (x1 y1,x2 y2,x3 y3,x4 y4)
#define ARG5(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5) (x1 y1,x2 y2,x3 y3,x4 y4,x5 y5)
#define ARG6(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6) \
			(x1 y1,x2 y2,x3 y3,x4 y4,x5 y5,x6 y6)
#define ARG7(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7) \
			(x1 y1,x2 y2,x3 y3,x4 y4,x5 y5,x6 y6,x7 y7)
#define ARG8(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7,x8,y8) \
			(x1 y1,x2 y2,x3 y3,x4 y4,x5 y5,x6 y6,x7 y7,x8 y8)
#define ARG9(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7,x8,y8,x9,y9) \
			(x1 y1,x2 y2,x3 y3,x4 y4,x5 y5,x6 y6,x7 y7,x8 y8,x9 y9)
#define ARG10(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7,x8,y8,x9,y9,xa,ya) \
			(x1 y1,x2 y2,x3 y3,x4 y4,x5 y5,x6 y6,x7 y7,x8 y8,x9 y9,xa ya)

#ifdef WITHPTHREADS
#define BARG0 (ALLPRIVATES *B)
#define BARG1(x1,y1) (ALLPRIVATES *B,x1 y1)
#define BARG2(x1,y1,x2,y2) (ALLPRIVATES *B,x1 y1,x2 y2)
#define BARG3(x1,y1,x2,y2,x3,y3) (ALLPRIVATES *B,x1 y1,x2 y2,x3 y3)
#define BARG4(x1,y1,x2,y2,x3,y3,x4,y4) (ALLPRIVATES *B,x1 y1,x2 y2,x3 y3,x4 y4)
#define BARG5(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5) (ALLPRIVATES *B,x1 y1,x2 y2,x3 y3,x4 y4,x5 y5)
#define BARG6(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6) \
			(ALLPRIVATES *B,x1 y1,x2 y2,x3 y3,x4 y4,x5 y5,x6 y6)
#define BARG7(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7) \
			(ALLPRIVATES *B,x1 y1,x2 y2,x3 y3,x4 y4,x5 y5,x6 y6,x7 y7)
#define BARG8(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7,x8,y8) \
			(ALLPRIVATES *B,x1 y1,x2 y2,x3 y3,x4 y4,x5 y5,x6 y6,x7 y7,x8 y8)
#define BARG9(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7,x8,y8,x9,y9) \
			(ALLPRIVATES *B,x1 y1,x2 y2,x3 y3,x4 y4,x5 y5,x6 y6,x7 y7,x8 y8,x9 y9)
#define BARG10(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7,x8,y8,x9,y9,xa,ya) \
			(ALLPRIVATES *B,x1 y1,x2 y2,x3 y3,x4 y4,x5 y5,x6 y6,x7 y7,x8 y8,x9 y9,xa ya)
#else
#define BARG0 ARG0
#define BARG1(x1,y1) (x1 y1)
#define BARG2(x1,y1,x2,y2) (x1 y1,x2 y2)
#define BARG3(x1,y1,x2,y2,x3,y3) (x1 y1,x2 y2,x3 y3)
#define BARG4(x1,y1,x2,y2,x3,y3,x4,y4) (x1 y1,x2 y2,x3 y3,x4 y4)
#define BARG5(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5) (x1 y1,x2 y2,x3 y3,x4 y4,x5 y5)
#define BARG6(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6) \
			(x1 y1,x2 y2,x3 y3,x4 y4,x5 y5,x6 y6)
#define BARG7(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7) \
			(x1 y1,x2 y2,x3 y3,x4 y4,x5 y5,x6 y6,x7 y7)
#define BARG8(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7,x8,y8) \
			(x1 y1,x2 y2,x3 y3,x4 y4,x5 y5,x6 y6,x7 y7,x8 y8)
#define BARG9(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7,x8,y8,x9,y9) \
			(x1 y1,x2 y2,x3 y3,x4 y4,x5 y5,x6 y6,x7 y7,x8 y8,x9 y9)
#define BARG10(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7,x8,y8,x9,y9,xa,ya) \
			(x1 y1,x2 y2,x3 y3,x4 y4,x5 y5,x6 y6,x7 y7,x8 y8,x9 y9,xa ya)
#endif
#define DECLARE(x,y) x y ;
 
#else

#define ARG0 ()
#define ARG1(x1,y1) (y1) x1 y1;
#define ARG2(x1,y1,x2,y2) (y1,y2) x1 y1;x2 y2;
#define ARG3(x1,y1,x2,y2,x3,y3) (y1,y2,y3) x1 y1;x2 y2;x3 y3;
#define ARG4(x1,y1,x2,y2,x3,y3,x4,y4) (y1,y2,y3,y4) x1 y1;x2 y2;x3 y3;x4 y4;
#define ARG5(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5) (y1,y2,y3,y4,y5) \
			 x1 y1;x2 y2;x3 y3;x4 y4;x5 y5;
#define ARG6(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6) (y1,y2,y3,y4,y5,y6) \
			 x1 y1;x2 y2;x3 y3;x4 y4;x5 y5;x6 y6;
#define ARG7(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7) \
			(y1,y2,y3,y4,y5,y6,y7) \
			 x1 y1;x2 y2;x3 y3;x4 y4;x5 y5;x6 y6;x7 y7;
#define ARG8(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7,x8,y8) \
			(y1,y2,y3,y4,y5,y6,y7,y8) \
			 x1 y1;x2 y2;x3 y3;x4 y4;x5 y5;x6 y6;x7 y7;x8 y8;
#define ARG9(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7,x8,y8,x9,y9) \
			(y1,y2,y3,y4,y5,y6,y7,y8,y9) \
			 x1 y1;x2 y2;x3 y3;x4 y4;x5 y5;x6 y6;x7 y7;x8 y8;x9 y9;
#define ARG10(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7,x8,y8,x9,y9,xa,ya) \
			(y1,y2,y3,y4,y5,y6,y7,y8,y9,ya) \
			 x1 y1;x2 y2;x3 y3;x4 y4;x5 y5;x6 y6;x7 y7;x8 y8;x9 y9;xa ya;
#define DECLARE(x,y) x();

#endif
/*
  	#] ARG definitions : 
  	#[ Macro's :
*/

#define MaX(x,y) ((x) > (y) ? (x): (y))
#define MiN(x,y) ((x) < (y) ? (x): (y))
#define ABS(x) ( (x) < 0 ? -(x): (x) )
#define REDLENG(x) ((((x)<0)?((x)+1):((x)-1))>>1)
#define INCLENG(x) (((x)<0)?(((x)<<1)-1):(((x)<<1)+1))
#define GETCOEF(x,y) x += *x;y = x[-1];x -= ABS(y);y=REDLENG(y)
#define GETSTOP(x,y) y=x+(*x)-1;y -= ABS(*y)-1
#define MULWWL(x,y) (x)*(y)
#define MULLONG1(b,nb,norm,e,ne,i,t,v) {                   \
		for ( i = 0, t = 0, v = (RLONG)norm; i < nb; i++ ) \
		  { t += b[i] * v; e[i] = t; t >>= BITSINWORD; }   \
		ne = nb; if ( t ) e[ne++] = t;     }
 
#define TOKENTOLINE(x,y) if ( AC.OutputSpaces == NOSPACEFORMAT ) { \
		TokenToLine((UBYTE *)(y)); } else { TokenToLine((UBYTE *)(x)); }

#define UngetFromStream(stream,c) ((stream)->nextchar[(stream)->isnextchar++]=c)
#define StreamPosition(stream) ((stream)->bufferposition + \
	((stream)->pointer - (stream)->buffer))
#ifdef WITHRETURN
#define AddLineFeed(s,n) { (s)[(n)++] = CARRIAGERETURN; (s)[(n)++] = LINEFEED; }
#else
#define AddLineFeed(s,n) { (s)[(n)++] = LINEFEED; }
#endif
#define TryRecover(x) Terminate(-1)
#define UngetChar(c) { pushbackchar = c; }
#define ParseNumber(x,s) {(x)=0;while(*(s)>='0'&&*(s)<='9')(x)=10*(x)+*(s)++ -'0';}
#define ParseSign(sgn,s) {(sgn)=0;while(*(s)=='-'||*(s)=='+'){\
          if ( *(s)++ == '-' ) sgn ^= 1;}}
#define ParseSignedNumber(x,s) { int sgn; ParseSign(sgn,s)\
          ParseNumber(x,s) if ( sgn ) x = -x; }
#define NCOPY(s,t,n) while ( --n >= 0 ) *s++ = *t++;
#define NeedNumber(x,s,err) { int sgn = 1;                               \
		while ( *s == ' ' || *s == '\t' || *s == '-' || *s == '+' ) {    \
			if ( *s == '-' ) sgn = -sgn; s++; }                          \
		if ( chartype[*s] != 1 ) goto err;                               \
		ParseNumber(x,s)                                                 \
		if ( sgn < 0 ) (x) = -(x); while ( *s == ' ' || *s == '\t' ) s++;\
	}
#define SKIPBLANKS(s) { while ( *(s) == ' ' || *(s) == '\t' ) (s)++; }
#define FLUSHCONSOLE if ( AP.InOutBuf > 0 ) CharOut(LINEFEED)

#define SKIPBRA1(s) { int lev1=0; s++; while(*s) { if(*s=='[')lev1++; \
					else if(*s==']'&&--lev1<0)break; s++;} }
#define SKIPBRA2(s) { int lev2=0; s++; while(*s) { if(*s=='{')lev2++; \
					else if(*s=='}'&&--lev2<0)break; \
					else if(*s=='[')SKIPBRA1(s) s++;} }
#define SKIPBRA3(s) { int lev3=0; s++; while(*s) { if(*s=='(')lev3++; \
					else if(*s==')'&&--lev3<0)break; \
					else if(*s=='{')SKIPBRA2(s) \
					else if(*s=='[')SKIPBRA1(s) s++;} }
#define SKIPBRA4(s) { int lev4=0; s++; while(*s) { if(*s=='(')lev4++; \
					else if(*s==')'&&--lev4<0)break; \
					else if(*s=='[')SKIPBRA1(s) s++;} }
#define SKIPBRA5(s) { int lev5=0; s++; while(*s) { if(*s=='{')lev5++; \
					else if(*s=='}'&&--lev5<0)break; \
					else if(*s=='(')SKIPBRA4(s) \
					else if(*s=='[')SKIPBRA1(s) s++;} }

#define AddToCB(c,wx) if(c->Pointer>=c->Top) \
		DoubleCbuffer(c-cbuf,c->Pointer); \
		*(c->Pointer)++ = wx;

#define EXCHINOUT { FILEHANDLE *ffFi = AR.outfile; \
	AR.outfile = AR.infile; AR.infile = ffFi; }
#define BACKINOUT { FILEHANDLE *ffFi = AR.outfile; POSITION posi; \
	AR.outfile = AR.infile; AR.infile = ffFi; \
	SetEndScratch(AR.infile,&posi); }

#if ARGHEAD > 2
#define FILLARG(w) { int i = ARGHEAD-2; while ( --i >= 0 ) *w++ = 0; }
#define COPYARG(w,t) { int i = ARGHEAD-2; while ( --i >= 0 ) *w++ = *t++; }
#else
#define FILLARG(w)
#define COPYARG(w,t)
#endif

#if FUNHEAD > 2
#define FILLFUN(w) { *w++ = 0; FILLFUN3(w) }
#else
#define FILLFUN(w)
#endif

#if FUNHEAD > 3
#define FILLFUN3(w) { int ie = FUNHEAD-3; while ( --ie >= 0 ) *w++ = 0; }
#define COPYFUN3(w,t) { int ie = FUNHEAD-3; while ( --ie >= 0 ) *w++ = *t++; }
#else
#define COPYFUN3(w,t)
#define FILLFUN3(w)
#endif

#if SUBEXPSIZE > 5
#define FILLSUB(w) { int ie = SUBEXPSIZE-5; while ( --ie >= 0 ) *w++ = 0; }
#define COPYSUB(w,ww) { int ie = SUBEXPSIZE-5; while ( --ie >= 0 ) *w++ = *ww++; }
#else
#define FILLSUB(w)
#define COPYSUB(w,ww)
#endif

#if EXPRHEAD > 4
#define FILLEXPR(w) { int ie = EXPRHEAD-4; while ( --ie >= 0 ) *w++ = 0; }
#else
#define FILLEXPR(w)
#endif

#define NEXTARG(x) if(*x>0) x += *x; else if(*x <= -FUNCTION)x++; else x += 2;
#define GETSETNUM(y) (((y)[2]==4)?((LONG)(y)[4]):\
	((((LONG)(y)[4])<<(BITSINWORD-1))+(LONG)(y)[5]))

#define TABLESIZE(a,b) (((WORD)sizeof(a))/((WORD)sizeof(b)))
#define WORDDIF(x,y) (WORD)(x-y)
#define POINDIF(x,y) (WORD)(x-y)
#define LONGDIF(x,y) (WORD)(x-y)
#define wsizeof(a) ((WORD)sizeof(a))
#define VARNAME(type,num) (AC.varnames->namebuffer+type[num].name)
#define DOLLARNAME(type,num) (AC.dollarnames->namebuffer+type[num].name)
#define EXPRNAME(num) (AC.exprnames->namebuffer+Expressions[num].name)
 
#define PREV(x) prevorder?prevorder:x

#define SETERROR(x) { Terminate(-1); return(-1); }

#ifdef _FILE_OFFSET_BITS
#if _FILE_OFFSET_BITS==64
/*:[19mar2004 mt]*/

#define ADDPOS(pp,x) (pp).p1 = ((pp).p1+(off_t)(x))
#define SETBASELENGTH(ss,x) (ss).p1 = (off_t)(x)
#define SETBASEPOSITION(pp,x) (pp).p1 = (off_t)(x)
#define ISEQUALPOSINC(pp1,pp2,x) ( (pp1).p1 == ((pp2).p1+(off_t)(x)) )
#define ISGEPOSINC(pp1,pp2,x) ( (pp1).p1 >= ((pp2).p1+(off_t)(x)) )
#define DIVPOS(pp,n) ( (pp).p1/(off_t)(n) )
#define MULPOS(pp,n) (pp).p1 *= (off_t)(n)

#else

#define ADDPOS(pp,x) (pp).p1 = ((pp).p1+(x))
#define SETBASELENGTH(ss,x) (ss).p1 = (x)
#define SETBASEPOSITION(pp,x) (pp).p1 = (x)
#define ISEQUALPOSINC(pp1,pp2,x) ( (pp1).p1 == ((pp2).p1+(LONG)(x)) )
#define ISGEPOSINC(pp1,pp2,x) ( (pp1).p1 >= ((pp2).p1+(LONG)(x)) )
#define DIVPOS(pp,n) ( (pp).p1/(n) )
#define MULPOS(pp,n) (pp).p1 *= (n)
#endif
#else

#define ADDPOS(pp,x) (pp).p1 = ((pp).p1+(LONG)(x))
#define SETBASELENGTH(ss,x) (ss).p1 = (LONG)(x)
#define SETBASEPOSITION(pp,x) (pp).p1 = (LONG)(x)
#define ISEQUALPOSINC(pp1,pp2,x) ( (pp1).p1 == ((pp2).p1+(LONG)(x)) )
#define ISGEPOSINC(pp1,pp2,x) ( (pp1).p1 >= ((pp2).p1+(LONG)(x)) )
#define DIVPOS(pp,n) ( (pp).p1/(LONG)(n) )
#define MULPOS(pp,n) (pp).p1 *= (LONG)(n)

#endif
#define DIFPOS(ss,pp1,pp2) (ss).p1 = ((pp1).p1-(pp2).p1)
#define DIFBASE(pp1,pp2) ((pp1).p1-(pp2).p1)
#define ADD2POS(pp1,pp2) (pp1).p1 += (pp2).p1
#define PUTZERO(pp) (pp).p1 = 0
#define BASEPOSITION(pp) ((pp).p1)
#define SETSTARTPOS(pp) (pp).p1 = -2
#define NOTSTARTPOS(pp) ( (pp).p1 > -2 )
#define ISMINPOS(pp) ( (pp).p1 == -1 )
#define ISEQUALPOS(pp1,pp2) ( (pp1).p1 == (pp2).p1 )
#define ISNOTEQUALPOS(pp1,pp2) ( (pp1).p1 != (pp2).p1 )
#define ISLESSPOS(pp1,pp2) ( (pp1).p1 < (pp2).p1 )
#define ISGEPOS(pp1,pp2) ( (pp1).p1 >= (pp2).p1 )
#define ISNOTZEROPOS(pp) ( (pp).p1 != 0 )
#define ISPOSPOS(pp) ( (pp).p1 > 0 )
#define ISNEGPOS(pp) ( (pp).p1 < 0 )
DECLARE(VOID TELLFILE,(int,POSITION *))

#define TOLONG(x) ((LONG)(x))
#define StrIcmp(x,y) StrICont((UBYTE *)(y),(UBYTE *)(x))

#define Add2Com(x) { WORD cod[2]; cod[0] = x; cod[1] = 2; AddNtoL(2,cod); }
#define Add3Com(x1,x2) { WORD cod[3]; cod[0] = x1; cod[1] = 3; cod[2] = x2; AddNtoL(3,cod); }
#define Add4Com(x1,x2,x3) { WORD cod[4]; cod[0] = x1; cod[1] = 4; \
   cod[2] = x2; cod[3] = x3; AddNtoL(4,cod); }
#define Add5Com(x1,x2,x3,x4) { WORD cod[5]; cod[0] = x1; cod[1] = 5; \
   cod[2] = x2; cod[3] = x3; cod[4] = x4; AddNtoL(5,cod); }

#define WantAddPointers(x) while((AT.pWorkPointer+(x))>AR.pWorkSize)\
	ExpandBuffer((void **)(&AT.pWorkSpace),&AR.pWorkSize,sizeof(WORD *))
#define WantAddLongs(x) while((AT.lWorkPointer+(x))>AR.lWorkSize)\
	ExpandBuffer((void **)(&AT.lWorkSpace),&AR.lWorkSize,sizeof(LONG))
#define WantAddPositions(x) while((AT.posWorkPointer+(x))>AR.posWorkSize)\
	ExpandBuffer((void **)(&AT.posWorkSpace),&AR.posWorkSize,sizeof(POSITION))

/*
  	#] Macro's : 
  	#[ Thread objects :
*/

#ifdef WITHPTHREADS

#define EXTERNLOCK(x) extern pthread_mutex_t x;
#define INILOCK(x)    pthread_mutex_t x = PTHREAD_MUTEX_INITIALIZER
#ifdef DEBUGGINGLOCKS
#include <asm/errno.h>
#define LOCK(x)       while ( pthread_mutex_trylock(&(x)) == EBUSY ) {}
#else
#define LOCK(x)       pthread_mutex_lock(&(x))
#endif
#define UNLOCK(x)     pthread_mutex_unlock(&(x))
#define GETBIDENTITY
#ifdef ITHREADS
#define GETIDENTITY   int identity = WhoAmI();
#else
#define GETIDENTITY   int identity = WhoAmI(); ALLPRIVATES *B = AB[identity];
#endif
#else

#define EXTERNLOCK(x)
#define INILOCK(x)
#define LOCK(x) 
#define UNLOCK(x)
#define GETIDENTITY
#define GETBIDENTITY

#endif

/*
  	#] Thread objects : 
  	#[ Declarations :
*/

/**
 *	All functions (well, nearly all) are declared here.
 *	This is done with the macro DECLARE which allows us to distinguish
 *	between various flavours of the C language.
 *	This was especially relevant in the days of K&R compilers and ANSI
 *	compilers existing side by side.
 */

DECLARE(VOID StartVariables,ARG0)
DECLARE(VOID setSignalHandlers,ARG0)
DECLARE(UBYTE *CodeToLine,(WORD,UBYTE *))
DECLARE(INDEXENTRY *FindInIndex,(WORD,FILEDATA *,WORD))
DECLARE(UBYTE *GetLine,(UBYTE *,LONG,WORD))
DECLARE(UBYTE *GetOneSet,(UBYTE *,WORD *,WORD *,WORD *,WORD *,WORD))
DECLARE(INDEXENTRY *NextFileIndex,(POSITION *))
DECLARE(UBYTE *NextWord,(UBYTE *))
DECLARE(WORD *PasteTerm,(PHEAD WORD,WORD *,WORD *,WORD,WORD))
DECLARE(UBYTE *SkipExpression,(UBYTE *,WORD))
DECLARE(UBYTE *SkipLine,(UBYTE *))
DECLARE(UBYTE *SkipName,(UBYTE *))
DECLARE(UBYTE *SkipOneName,(UBYTE *))
DECLARE(UBYTE *SkipSet,(UBYTE *))
DECLARE(UBYTE *StrCopy,(UBYTE *,UBYTE *))
DECLARE(UBYTE *WrtPower,(UBYTE *,WORD))
DECLARE(WORD AccumGCD,(UWORD *,WORD *,UWORD *,WORD))
DECLARE(VOID AddArgs,(PHEAD WORD *,WORD *,WORD *))
DECLARE(WORD AddCoef,(PHEAD WORD **,WORD **))
DECLARE(WORD AddLong,(UWORD *,WORD,UWORD *,WORD,UWORD *,WORD *))
DECLARE(WORD AddPLon,(UWORD *,WORD,UWORD *,WORD,UWORD *,UWORD *))
DECLARE(WORD AddPoly,(PHEAD WORD **,WORD **))
DECLARE(WORD AddRat,(PHEAD UWORD *,WORD,UWORD *,WORD,UWORD *,WORD *))
DECLARE(VOID AddToLine,(UBYTE *))
DECLARE(WORD AddWild,(PHEAD WORD,WORD,WORD))
DECLARE(WORD BigLong,(UWORD *,WORD,UWORD *,WORD))
DECLARE(WORD BinomGen,(WORD *,WORD,WORD **,WORD,WORD,WORD,WORD,WORD,UWORD *,WORD))
DECLARE(VOID Cconout,(WORD))
DECLARE(WORD CheckWild,(PHEAD WORD,WORD,WORD,WORD *))
DECLARE(WORD Chisholm,(PHEAD WORD *term,WORD level))
DECLARE(WORD CleanExpr,(WORD))
DECLARE(VOID CleanUp,(WORD))
DECLARE(VOID ClearWild,(PHEAD0))
DECLARE(WORD Commute,(WORD *,WORD *))
DECLARE(WORD DetCommu,(WORD *))
DECLARE(int CompArg,(WORD *,WORD *))
DECLARE(WORD CompCoef,(WORD *, WORD *))
DECLARE(WORD CompGroup,(PHEAD WORD,WORD **,WORD *,WORD *,WORD))
DECLARE(WORD CompWord,(UBYTE *,char *))
DECLARE(WORD Compare1,(PHEAD WORD *,WORD *,WORD))
DECLARE(WORD CopyToComp,ARG0)
DECLARE(WORD CountDo,(WORD *,WORD *))
DECLARE(WORD CountFun,(WORD *,WORD *))
DECLARE(WORD Deferred,(PHEAD WORD *,WORD))
DECLARE(WORD DeleteStore,(WORD))
DECLARE(WORD DetCurDum,(WORD *))
DECLARE(VOID DetVars,(WORD *,WORD))
DECLARE(WORD Distribute,(DISTRIBUTE *,WORD))
DECLARE(WORD DivLong,(UWORD *,WORD,UWORD *,WORD,UWORD *,WORD *,UWORD *,WORD *))
DECLARE(WORD DivRat,(PHEAD UWORD *,WORD,UWORD *,WORD,UWORD *,WORD *))
DECLARE(WORD Divvy,(PHEAD UWORD *,WORD *,UWORD *,WORD))
DECLARE(WORD DoDelta,(WORD *))
DECLARE(WORD DoDelta3,(WORD *,WORD))
DECLARE(WORD DoTableExpansion,(WORD *,WORD))
DECLARE(WORD DoDistrib,(PHEAD WORD *,WORD))
DECLARE(WORD DoMerge,(WORD *,WORD,WORD,WORD))
DECLARE(WORD TestUse,(WORD *,WORD))
DECLARE(DBASE *FindTB,(UBYTE *))
DECLARE(int CheckTableDeclarations,(DBASE *))
DECLARE(WORD Apply,(WORD *,WORD))
DECLARE(int ApplyExec,(WORD *,int,WORD))
DECLARE(WORD ApplyReset,(WORD))
DECLARE(WORD TableReset,ARG0)
DECLARE(VOID ReWorkT,(WORD *,WORD *,WORD))
DECLARE(WORD DoIfStatement,(WORD *,WORD *))
DECLARE(WORD DoModule,ARG0)
DECLARE(WORD DoOnePow,(WORD *,WORD,WORD,WORD *,WORD *,WORD,WORD *))
DECLARE(void DoRevert,(WORD *,WORD *))
DECLARE(WORD DoSumF1,(PHEAD WORD *,WORD *,WORD,WORD))
DECLARE(WORD DoSumF2,(PHEAD WORD *,WORD *,WORD,WORD))
DECLARE(WORD DoTheta,(WORD *))
DECLARE(LONG EndSort,(WORD *,int))
DECLARE(WORD EntVar,(WORD,UBYTE *,WORD,WORD,WORD))
DECLARE(WORD EpfCon,(PHEAD WORD *,WORD *,WORD,WORD))
DECLARE(WORD EpfFind,(PHEAD WORD *,WORD *))
DECLARE(WORD EpfGen,(WORD,WORD *,WORD *,WORD *,WORD))
DECLARE(WORD EqualArg,(WORD *,WORD,WORD))
DECLARE(WORD Evaluate,(UBYTE **))
DECLARE(int Factorial,(PHEAD WORD,UWORD *,WORD *))
DECLARE(int Bernoulli,(WORD,UWORD *,WORD *))
DECLARE(int FactorIn,(PHEAD WORD *,WORD))
DECLARE(int FactorInExpr,(PHEAD WORD *,WORD))
DECLARE(WORD FindAll,(PHEAD WORD *,WORD *,WORD,WORD *))
DECLARE(WORD FindMulti,(PHEAD WORD *,WORD *))
DECLARE(WORD FindOnce,(PHEAD WORD *,WORD *))
DECLARE(WORD FindOnly,(PHEAD WORD *,WORD *))
DECLARE(WORD FindRest,(PHEAD WORD *,WORD *))
DECLARE(WORD FindSpecial,(WORD *))
DECLARE(WORD FindrNumber,(WORD,VARRENUM *))
DECLARE(VOID FiniLine,ARG0)
DECLARE(WORD FiniTerm,(PHEAD WORD *,WORD *,WORD *,WORD,WORD))
DECLARE(VOID FlushCon,ARG0)
DECLARE(WORD FlushOut,(POSITION *,FILEHANDLE *,int))
DECLARE(VOID FunLevel,(PHEAD WORD *))
DECLARE(VOID GarbHand,ARG0)
DECLARE(WORD GcdLong,(PHEAD UWORD *,WORD,UWORD *,WORD,UWORD *,WORD *))
DECLARE(VOID GCD,(UWORD *,WORD,UWORD *,WORD,UWORD *,WORD *))
DECLARE(ULONG GCD2,(ULONG,ULONG))
DECLARE(WORD Generator,(PHEAD WORD *,WORD))
DECLARE(LONG Get1Long,(UBYTE *))
DECLARE(WORD GetBinom,(UWORD *,WORD *,WORD,WORD))
DECLARE(WORD GetFromStore,(WORD *,POSITION *,RENUMBER,WORD *,WORD))
DECLARE(WORD GetIchar,ARG0)
DECLARE(WORD GetIword,(UBYTE *,WORD))
DECLARE(WORD GetLong,(UBYTE *,UWORD *,WORD *))
DECLARE(WORD GetMoreTerms,(WORD *))
DECLARE(WORD GetMoreFromMem,(WORD *,WORD **))
DECLARE(WORD GetObject,(UBYTE *,WORD *,WORD *,WORD))
DECLARE(WORD GetOneTerm,(PHEAD WORD *,FILEHANDLE *,POSITION *,int))
DECLARE(WORD GetOption,(UBYTE **))
DECLARE(WORD GetParams,ARG0)
DECLARE(RENUMBER GetTable,(WORD,POSITION *))
DECLARE(WORD GetTerm,(PHEAD WORD *))
DECLARE(WORD GetWithEcho,ARG0)
DECLARE(WORD Glue,(PHEAD WORD *,WORD *,WORD *,WORD))
DECLARE(WORD InFunction,(WORD *,WORD *))
DECLARE(WORD IncLHS,ARG0)
DECLARE(WORD IncRHS,(WORD))
DECLARE(VOID IniGlob,ARG0)
DECLARE(VOID IniLine,ARG0)
DECLARE(WORD IniVars,ARG0)
DECLARE(VOID Init2,ARG0)
DECLARE(VOID Initialize,ARG0)
DECLARE(WORD InsertTerm,(PHEAD WORD *,WORD,WORD,WORD *,WORD *,WORD))
DECLARE(WORD Kraak,(UBYTE *,WORD **,WORD *,WORD,WORD))
DECLARE(VOID LongToLine,(UWORD *,WORD))
DECLARE(WORD LookAhead,ARG0)
DECLARE(WORD MakeDirty,(WORD *,WORD *,WORD))
DECLARE(VOID MarkDirty,(WORD *,WORD))
DECLARE(WORD MakeModTable,ARG0)
DECLARE(WORD MatchE,(WORD *,WORD *,WORD *,WORD))
DECLARE(int MatchCy,(WORD *,WORD *,WORD *,WORD))
DECLARE(int FunMatchCy,(WORD *,WORD *,WORD *,WORD))
DECLARE(int FunMatchSy,(WORD *,WORD *,WORD *,WORD))
DECLARE(int MatchArgument,(WORD *,WORD *))
DECLARE(WORD MatchFunction,(PHEAD WORD *,WORD *,WORD *))
DECLARE(WORD MergePatches,(WORD))
DECLARE(WORD MesCerr,(char *, UBYTE *))
DECLARE(WORD MesComp,(char *, UBYTE *, UBYTE *))
DECLARE(WORD MesLong,(char *))
DECLARE(WORD MesPar,(WORD))
DECLARE(WORD MesSet,(WORD))
DECLARE(WORD Modulus,(WORD *))
DECLARE(VOID MoveDummies,(PHEAD WORD *,WORD))
DECLARE(WORD MulLong,(UWORD *,WORD,UWORD *,WORD,UWORD *,WORD *))
DECLARE(WORD MulRat,(PHEAD UWORD *,WORD,UWORD *,WORD,UWORD *,WORD *))
DECLARE(WORD Mully,(PHEAD UWORD *,WORD *,UWORD *,WORD))
DECLARE(WORD MultDo,(WORD *,WORD *))
DECLARE(WORD NewSort,ARG0)
DECLARE(WORD ExtraSymbol,(WORD,WORD,WORD,WORD *))
DECLARE(WORD Normalize,(PHEAD WORD *))
DECLARE(WORD OpenTemp,ARG0)
DECLARE(VOID Pack,(UWORD *,WORD *,UWORD *,WORD ))
DECLARE(LONG PasteFile,(WORD,WORD *,POSITION *,WORD **,RENUMBER,WORD *,WORD))
DECLARE(WORD Permute,(PERM *,WORD))
DECLARE(WORD PolyFunMul,(PHEAD WORD *))
DECLARE(WORD PopVariables,ARG0)
DECLARE(WORD PrepPoly,(WORD *))
DECLARE(WORD Processor,ARG0)
DECLARE(WORD Product,(UWORD *,WORD *,WORD))
DECLARE(VOID PrtLong,(UWORD *,WORD,UBYTE *))
DECLARE(VOID PrtTerms,ARG0)
DECLARE(VOID PrintRunningTime,ARG0)
DECLARE(WORD PutBracket,(PHEAD WORD *))
DECLARE(LONG PutIn,(FILEHANDLE *,POSITION *,WORD *,WORD **,int))
DECLARE(WORD PutInStore,(INDEXENTRY *,WORD))
DECLARE(WORD PutOut,(PHEAD WORD *,POSITION *,FILEHANDLE *,WORD))
DECLARE(UWORD Quotient,(UWORD *,WORD *,WORD))
DECLARE(WORD RaisPow,(PHEAD UWORD *,WORD *,UWORD))
DECLARE(VOID RatToLine,(UWORD *,WORD))
DECLARE(WORD RatioFind,(PHEAD WORD *,WORD *))
DECLARE(WORD RatioGen,(PHEAD WORD *,WORD *,WORD,WORD))
DECLARE(WORD ReNumber,(PHEAD WORD *))
DECLARE(WORD ReadLHS,ARG0)
DECLARE(WORD ReadRHS,(WORD))
DECLARE(WORD ReadSnum,(UBYTE **))
DECLARE(WORD Remain10,(UWORD *,WORD *))
DECLARE(WORD Remain4,(UWORD *,WORD *))
DECLARE(WORD ResetScratch,ARG0)
DECLARE(WORD ResolveSet,(WORD *,WORD *,WORD *))
DECLARE(WORD Reverse5,(WORD *term,WORD level))
DECLARE(WORD RevertScratch,ARG0)
DECLARE(WORD ScanFunctions,(PHEAD WORD *,WORD *,WORD))
DECLARE(VOID SeekScratch,(FILEHANDLE *,POSITION *))
DECLARE(VOID SetEndScratch,(FILEHANDLE *,POSITION *))
DECLARE(VOID SetEndHScratch,(FILEHANDLE *,POSITION *))
DECLARE(WORD SetFileIndex,ARG0)
DECLARE(WORD SetParams,ARG0)
DECLARE(WORD Sflush,(FILEHANDLE *))
DECLARE(WORD Simplify,(PHEAD UWORD *,WORD *,UWORD *,WORD *))
DECLARE(WORD SkipWhite,ARG0)
DECLARE(WORD SortWild,(WORD *,WORD))
DECLARE(FILE *LocateBase,(char **,char **))
#ifdef NEWSPLITMERGE
DECLARE(LONG SplitMerge,(PHEAD WORD **,LONG))
#else
DECLARE(VOID SplitMerge,(PHEAD WORD **,LONG))
#endif
DECLARE(WORD StoreTerm,(PHEAD WORD *))
DECLARE(WORD StrCcmp,(UBYTE *, char *))
DECLARE(VOID StrNcop,(UBYTE *, UBYTE *, WORD))
DECLARE(WORD SubEval,(UBYTE **))
DECLARE(VOID SubPLon,(UWORD *,WORD,UWORD *,WORD,UWORD *,WORD *))
DECLARE(VOID Substitute,(PHEAD WORD *,WORD *,WORD))
DECLARE(WORD SymFind,(PHEAD WORD *,WORD *))
DECLARE(WORD SymGen,(PHEAD WORD *,WORD *,WORD,WORD))
DECLARE(WORD Symmetrize,(PHEAD WORD *,WORD *,WORD,WORD,WORD))
DECLARE(int FullSymmetrize,(WORD *,int))
DECLARE(WORD TakeModulus,(UWORD *,WORD *,WORD *,WORD,WORD))
DECLARE(VOID TalToLine,(UWORD))
DECLARE(WORD TenVec,(PHEAD WORD *,WORD *,WORD,WORD))
DECLARE(WORD TenVecFind,(PHEAD WORD *,WORD *))
DECLARE(WORD TermRenumber,(WORD *,RENUMBER,WORD))
DECLARE(VOID TestDrop,ARG0)
DECLARE(WORD TestMatch,(PHEAD WORD *,WORD *))
DECLARE(WORD TestSub,(PHEAD WORD *,WORD))
DECLARE(LONG TimeCPU,(WORD))
DECLARE(LONG TimeChildren,(WORD))
DECLARE(LONG TimeWallClock,(WORD))
DECLARE(LONG Timer,(int))
DECLARE(LONG GetWorkerTimes,ARG0)
DECLARE(WORD ToStorage,(EXPRESSIONS,POSITION *))
DECLARE(VOID TokenToLine,(UBYTE *))
DECLARE(WORD Trace4,(PHEAD WORD *,WORD *,WORD,WORD))
DECLARE(WORD Trace4Gen,(PHEAD TRACES *,WORD))
DECLARE(WORD Trace4no,(WORD,WORD *,TRACES *))
DECLARE(WORD TraceFind,(PHEAD WORD *,WORD *))
DECLARE(WORD TraceN,(PHEAD WORD *,WORD *,WORD,WORD))
DECLARE(WORD TraceNgen,(PHEAD TRACES *,WORD))
DECLARE(WORD TraceNno,(WORD,WORD *,TRACES *))
DECLARE(WORD Traces,(PHEAD WORD *,WORD *,WORD,WORD))
DECLARE(WORD Trick,(WORD *,TRACES *))
DECLARE(WORD TryDo,(WORD *,WORD *,WORD))
DECLARE(VOID UnDefine,(WORD))
DECLARE(VOID UnPack,(UWORD *,WORD,WORD *,WORD *))
DECLARE(WORD Unique,(UBYTE *,UBYTE *,WORD))
DECLARE(WORD VarStore,(UBYTE *,WORD,WORD,WORD))
DECLARE(VOID W_S_L,(WORD,LONG))
DECLARE(VOID W_S_S,(WORD,UBYTE *))
DECLARE(WORD WildFill,(PHEAD WORD *,WORD *,WORD *))
DECLARE(WORD WriteAll,ARG0)
DECLARE(WORD WriteOne,(UBYTE *,int,int))
DECLARE(VOID WriteArgument,(WORD *))
DECLARE(WORD WriteExpression,(WORD *,LONG))
DECLARE(WORD WriteInnerTerm,(WORD *,WORD))
DECLARE(VOID WriteLists,ARG0)
DECLARE(VOID WriteSetup,ARG0)
DECLARE(VOID WriteStats,(POSITION *,WORD))
DECLARE(WORD WriteSubTerm,(WORD *,WORD))
DECLARE(WORD WriteTerm,(WORD *,WORD *,WORD,WORD,WORD))
DECLARE(WORD execarg,(WORD *,WORD))
DECLARE(WORD execterm,(WORD *,WORD))
DECLARE(WORD execnorm,(WORD *,WORD))
DECLARE(VOID SpecialCleanup,(PHEAD0))
DECLARE(int main,(int,char **))

DECLARE(typedef WORD (*WCW),(EXPRESSIONS,WORD))
DECLARE(UBYTE *strDup,(UBYTE *))
DECLARE(WORD AddSetElement,(EXPRESSIONS,LONG))
DECLARE(WORD AddToHide,ARG0)
DECLARE(LONG CloseFormFile,(UBYTE *,WORD))
DECLARE(LONG CreateFormFile,(UBYTE *,WORD))
DECLARE(WORD DoExecute,(WORD,WORD))
DECLARE(WORD DoSpolynomial,(EXPRESSIONS,WORD,WORD,WORD *))
DECLARE(WORD ElimOneVar,(EXPRESSIONS,WORD))
DECLARE(WORD FromHide,ARG0)
DECLARE(WORD Groebner,(WORD))
DECLARE(WORD LinSolve,(WORD))
DECLARE(WORD MakeCommercial,(UBYTE *,LONG,LONG))
DECLARE(WORD MakeSubs,(WORD *,WORD,WORD))
DECLARE(WORD MulSetBracket,(WORD *,LONG,WORD *,WORD,LONG,LONG))
DECLARE(WORD NormalForm,ARG0)
DECLARE(LONG OpenFormFile,(UBYTE *,WORD))
DECLARE(VOID SetScratch,(FILEHANDLE *,POSITION *))
DECLARE(WORD SortByWeight,(EXPRESSIONS,WORD)) 
DECLARE(WORD Spolynomial,(EXPRESSIONS,LONG,LONG,LONG,LONG,WORD *,WORD *,WORD *,WORD))
DECLARE(WORD StepExpressions,(WORD,WORD))
DECLARE(WORD StepGroebner,(EXPRESSIONS,WORD))
DECLARE(WORD StepNormalForm,(EXPRESSIONS,WORD))
DECLARE(WORD TestLinearWeights,(UBYTE *))
DECLARE(WORD TestOneLinearWeight,(WORD))
DECLARE(WORD ToHide,ARG0)
DECLARE(WORD ToTriangle,(EXPRESSIONS,WORD))
DECLARE(VOID Warning,(char *))
DECLARE(VOID HighWarning,(char *))
DECLARE(LONG WriteFormFile,(UBYTE *,WORD))
DECLARE(int SpareTable,(TABLES))

DECLARE(UBYTE *strDup1,(UBYTE *,char *))
DECLARE(VOID *Malloc,(LONG))
DECLARE(VOID *Malloc1,(LONG,char *))
DECLARE(int DoTail,(int,UBYTE **))
DECLARE(int OpenInput,ARG0)
DECLARE(int PutPreVar,(UBYTE *,UBYTE *,UBYTE *,int))
DECLARE(VOID Error0,(char *))
DECLARE(VOID Error1,(char *,UBYTE *))
DECLARE(VOID Error2,(char *,char *,UBYTE *))
DECLARE(UBYTE ReadFromStream,(STREAM *))
DECLARE(UBYTE GetFromStream,(STREAM *))
DECLARE(UBYTE LookInStream,(STREAM *))
DECLARE(STREAM *OpenStream,(UBYTE *,int,int,int))
DECLARE(int LocateFile,(UBYTE **,int))
DECLARE(STREAM *CloseStream,(STREAM *))
DECLARE(VOID PositionStream,(STREAM *,LONG))
DECLARE(int ProcessOption,(UBYTE *,UBYTE *,int))
DECLARE(int DoSetups,ARG0)
DECLARE(VOID Terminate,(int))
DECLARE(NAMENODE *GetNode,(NAMETREE *,UBYTE *))
DECLARE(int AddName,(NAMETREE *,UBYTE *,WORD,WORD,int *))
DECLARE(int GetName,(NAMETREE *,UBYTE *,WORD *,int))
DECLARE(int GetAutoName,(UBYTE *,WORD *))
DECLARE(int GetVar,(UBYTE *,WORD *,WORD *,int,int))
DECLARE(int MakeDubious,(NAMETREE *,UBYTE *,WORD *))
DECLARE(int GetOName,(NAMETREE *,UBYTE *,WORD *,int))
DECLARE(VOID DumpTree,(NAMETREE *))
DECLARE(VOID DumpNode,(NAMETREE *,WORD,WORD))
DECLARE(VOID LinkTree,(NAMETREE *,WORD,WORD))
DECLARE(VOID CopyTree,(NAMETREE *,NAMETREE *,WORD))
DECLARE(int CompactifyTree,(NAMETREE *))
DECLARE(NAMETREE *MakeNameTree,ARG0)
DECLARE(VOID FreeNameTree,(NAMETREE *))
DECLARE(int AddExpression,(UBYTE *,int,int))
DECLARE(int AddSymbol,(UBYTE *,int,int,int))
DECLARE(int AddDollar,(UBYTE *,WORD,WORD *,LONG))
DECLARE(int ReplaceDollar,(WORD,WORD,WORD *,LONG))
DECLARE(int DollarRaiseLow,(UBYTE *,LONG))
DECLARE(int AddVector,(UBYTE *,int))
DECLARE(int AddDubious,(UBYTE *))
DECLARE(int AddIndex,(UBYTE *,int,int))
DECLARE(UBYTE *DoDimension,(UBYTE *,int *,int *))
DECLARE(int AddFunction,(UBYTE *,int,int,int,int))
DECLARE(int CoFunction,(UBYTE *,int,int))
DECLARE(int AddSet,(UBYTE *))
DECLARE(int DoElements,(UBYTE *,SETS,UBYTE *))
DECLARE(int DoTempSet,(UBYTE *,UBYTE *))
DECLARE(int NameConflict,(int,UBYTE *))
DECLARE(int OpenFile,(char *))
DECLARE(int OpenAddFile,(char *))
DECLARE(int CreateFile,(char *))
DECLARE(int CreateLogFile,(char *))
DECLARE(VOID CloseFile,(int))
DECLARE(int CreateHandle,ARG0)
DECLARE(LONG ReadFile,(int,UBYTE *,LONG))
DECLARE(LONG ReadPosFile,(PHEAD FILEHANDLE *,UBYTE *,LONG,POSITION *))
DECLARE(LONG WriteFileToFile,(int,UBYTE *,LONG))
DECLARE(VOID SeekFile,(int,POSITION *,int))
DECLARE(LONG TellFile,(int))
DECLARE(void FlushFile,(int))
DECLARE(int GetPosFile,(int,fpos_t *))
DECLARE(int SetPosFile,(int,fpos_t *))
DECLARE(VOID SynchFile,(int))
DECLARE(VOID TruncateFile,(int))
DECLARE(int GetChannel,(char *))
DECLARE(int GetAppendChannel,(char *))
DECLARE(int CloseChannel,(char *))
DECLARE(VOID inictable,ARG0)
DECLARE(KEYWORD *findcommand,(UBYTE *))
DECLARE(int inicbufs,ARG0)
DECLARE(VOID StartFiles,ARG0)
DECLARE(UBYTE *MakeDate,ARG0)
DECLARE(VOID PreProcessor,ARG0)
DECLARE(VOID *FromList,(LIST *))
DECLARE(VOID *From0List,(LIST *))
DECLARE(VOID *FromVarList,(LIST *))
DECLARE(int DoubleList,(VOID ***,int *,int,char *))
DECLARE(int DoubleLList,(VOID ***,LONG *,int,char *))
DECLARE(void DoubleBuffer,(void **,void **,int,char *))
DECLARE(void ExpandBuffer,(void **,LONG *,int))
DECLARE(LONG iexp,(LONG,int))
DECLARE(int IsLikeVector,(WORD *))
DECLARE(int CompareArgs,(WORD *,WORD *))
DECLARE(UBYTE *SkipField,(UBYTE *,int))
DECLARE(int StrCmp,(UBYTE *,UBYTE *))
DECLARE(int StrICmp,(UBYTE *,UBYTE *))
DECLARE(int StrHICmp,(UBYTE *,UBYTE *))
DECLARE(int StrICont,(UBYTE *,UBYTE *))
DECLARE(int ConWord,(UBYTE *,UBYTE *))
DECLARE(int StrLen,(UBYTE *))
DECLARE(UBYTE *GetPreVar,(UBYTE *,int))
DECLARE(void ToGeneral,(WORD *,WORD *,WORD))
DECLARE(int ToFast,(WORD *,WORD *))
DECLARE(SETUPPARAMETERS *GetSetupPar,(UBYTE *))
DECLARE(int RecalcSetups,ARG0)
DECLARE(int AllocSetups,ARG0)
DECLARE(SORTING *AllocSort,(LONG,LONG,LONG,LONG,int,int,LONG))
DECLARE(int AllocScratchBuffers,ARG0)
DECLARE(VOID AllocSortFileName,(SORTING *))
DECLARE(UBYTE *LoadInputFile,(UBYTE *,int))
DECLARE(UBYTE GetInput,ARG0)
DECLARE(VOID ClearPushback,ARG0)
DECLARE(UBYTE GetChar,(int))
DECLARE(VOID CharOut,(UBYTE))
DECLARE(VOID UnsetAllowDelay,ARG0)
DECLARE(VOID PopPreVars,(int))
DECLARE(VOID IniModule,(int))
DECLARE(VOID IniSpecialModule,(int))
DECLARE(int ModuleInstruction,(int *,int *))
DECLARE(int PreProInstruction,ARG0)
DECLARE(int LoadInstruction,(int))
DECLARE(int LoadStatement,(int))
DECLARE(KEYWORD *FindKeyWord,(UBYTE *,KEYWORD *,int))
DECLARE(KEYWORD *FindInKeyWord,(UBYTE *,KEYWORD *,int))
DECLARE(int DoDefine,(UBYTE *))
DECLARE(int DoRedefine,(UBYTE *))
DECLARE(int TheDefine,(UBYTE *,int))
DECLARE(int TheUndefine,(UBYTE *))
DECLARE(int ClearMacro,(UBYTE *))
DECLARE(int DoUndefine,(UBYTE *))
DECLARE(int DoInclude,(UBYTE *))
/*[14apr2004 mt]:*/
DECLARE(int DoExternal,(UBYTE *))
DECLARE(int DoToExternal,(UBYTE *))
DECLARE(int DoFromExternal,(UBYTE *))
DECLARE(int DoPrompt,(UBYTE *))
DECLARE(int DoSetExternal,(UBYTE *))
/*[10may2006 mt]:*/
DECLARE(int DoSetExternalAttr,(UBYTE *))
/*:[10may2006 mt]*/
DECLARE(int DoRmExternal,(UBYTE *))
/*:[14apr2004 mt]*/
DECLARE(int DoMessage,(UBYTE *))
DECLARE(int DoPreNormPoly,(UBYTE *))
DECLARE(int DoPreOut,(UBYTE *))
DECLARE(int DoPreAppend,(UBYTE *))
DECLARE(int DoPreCreate,(UBYTE *))
DECLARE(int DoPreAssign,(UBYTE *))
DECLARE(int DoPreBreak,(UBYTE *))
DECLARE(int DoPreDefault,(UBYTE *))
DECLARE(int DoPreSwitch,(UBYTE *))
DECLARE(int DoPreEndSwitch,(UBYTE *))
DECLARE(int DoPreCase,(UBYTE *))
DECLARE(int DoPreShow,(UBYTE *))
DECLARE(int DoPreExchange,(UBYTE *))
DECLARE(int DoSystem,(UBYTE *))
DECLARE(int DoPipe,(UBYTE *))
DECLARE(VOID StartPrepro,ARG0)
DECLARE(int DoIfdef,(UBYTE *,int))
DECLARE(int DoElse,(UBYTE *))
DECLARE(int DoElseif,(UBYTE *))
DECLARE(int DoEndif,(UBYTE *))
DECLARE(int DoTerminate,(UBYTE *))
DECLARE(int DoIf,(UBYTE *))
DECLARE(int DoCall,(UBYTE *))
DECLARE(int DoDebug,(UBYTE *))
DECLARE(int DoDo,(UBYTE *))
DECLARE(int DoEnddo,(UBYTE *))
DECLARE(int DoEndprocedure,(UBYTE *))
DECLARE(int DoProcedure,(UBYTE *))
DECLARE(int DoPrePrint,(UBYTE *))
DECLARE(int DoPreWrite,(UBYTE *))
DECLARE(int DoPreClose,(UBYTE *))
DECLARE(int DoPreRemove,(UBYTE *))
DECLARE(int DoCommentChar,(UBYTE *))
DECLARE(int DoPrcExtension,(UBYTE *))
DECLARE(VOID WriteString,(int,UBYTE *,int))
DECLARE(VOID WriteUnfinString,(int,UBYTE *,int))
DECLARE(UBYTE *PreCalc,ARG0)
DECLARE(UBYTE *PreEval,(UBYTE *,LONG *))
DECLARE(VOID NumToStr,(UBYTE *,LONG))
DECLARE(int PreCmp,(int,int,UBYTE *,int,int,UBYTE *,int))
DECLARE(int PreEq,(int,int,UBYTE *,int,int,UBYTE *,int))
DECLARE(UBYTE *pParseObject,(UBYTE *,int *,LONG *))
DECLARE(UBYTE *PreIfEval,(UBYTE *,int *))
DECLARE(int EvalPreIf,(UBYTE *))
DECLARE(int PreLoad,(PRELOAD *,UBYTE *,UBYTE *,int,char *))
DECLARE(int PreSkip,(UBYTE *,UBYTE *,int))
DECLARE(UBYTE *EndOfToken,(UBYTE *))
DECLARE(VOID SetSpecialMode,(int,int))
DECLARE(VOID MakeGlobal,ARG0)
DECLARE(int ExecModule,(int))
DECLARE(int ExecStore,ARG0)
DECLARE(VOID FullCleanUp,ARG0)
DECLARE(int DoExecStatement,ARG0)
DECLARE(int DoPipeStatement,ARG0)
DECLARE(int DoPolyfun,(UBYTE *))
DECLARE(int DoPolyratfun,(UBYTE *))
DECLARE(int CompileStatement,(UBYTE *))
DECLARE(UBYTE *ToToken,(UBYTE *))
DECLARE(int GetDollar,(UBYTE *))
DECLARE(int PutDollar,(UBYTE *))
DECLARE(int MesWork,ARG0)
DECLARE(int MesPrint,(char *,...))
DECLARE(int MesCall,(char *))
DECLARE(int Mes1arr,(char *))
DECLARE(int Mes2arr,(char *))
DECLARE(UBYTE *NumCopy,(WORD,UBYTE *))
DECLARE(char *LongCopy,(LONG,char *))
DECLARE(char *LongLongCopy,(off_t *,char *))
DECLARE(VOID ReserveTempFiles,(int))
DECLARE(VOID PrintTerm,(WORD *,char *))
DECLARE(VOID PrintSubTerm,(WORD *,char *))
DECLARE(VOID PrintWords,(WORD *,LONG))
DECLARE(int ExpandTripleDots,ARG0)
DECLARE(LONG ComPress,(WORD **,LONG *))
DECLARE(VOID StageSort,(FILEHANDLE *))

#define M_alloc(x)      malloc((size_t)(x))
DECLARE(void M_free,(VOID *,char *))
DECLARE(void ClearWildcardNames,ARG0)
DECLARE(int AddWildcardName,(UBYTE *))
DECLARE(int GetWildcardName,(UBYTE *))
DECLARE(void Globalize,(int))
DECLARE(void ResetVariables,(int))
DECLARE(void AddToPreTypes,(int))
DECLARE(void MessPreNesting,(int))
DECLARE(LONG GetStreamPosition,(STREAM *))
DECLARE(WORD *DoubleCbuffer,(int,WORD *))
DECLARE(WORD *AddLHS,(int))
DECLARE(WORD *AddRHS,(int,int))
DECLARE(int AddNtoL,(int,WORD *))
DECLARE(int AddNtoC,(int,WORD *))
DECLARE(VOID DoubleIfBuffers,ARG0)
DECLARE(STREAM *CreateStream,(UBYTE *))

DECLARE(int setonoff,(UBYTE *,int *,int,int))
DECLARE(int DoPrint,(UBYTE *,int))
DECLARE(int SetExpr,(UBYTE *,int,int))
DECLARE(void AddToCom,(int,WORD *))
DECLARE(int Add2ComStrings,(int,WORD *,UBYTE *,UBYTE *))
DECLARE(int DoSymmetrize,(UBYTE *,int))
DECLARE(int DoArgument,(UBYTE *,int))
DECLARE(int DoBrackets,(UBYTE *,int))
DECLARE(WORD *CountComp,(UBYTE *,WORD *))
DECLARE(int CoAntiBracket,(UBYTE *))
DECLARE(int CoAntiSymmetrize,(UBYTE *))
DECLARE(int DoArgPlode,(UBYTE *,int))
DECLARE(int CoArgExplode,(UBYTE *))
DECLARE(int CoArgImplode,(UBYTE *))
DECLARE(int CoArgument,(UBYTE *))
DECLARE(int CoInside,(UBYTE *))
DECLARE(int DoInside,(UBYTE *))
DECLARE(int CoInExpression,(UBYTE *))
DECLARE(int CoInParallel,(UBYTE *))
DECLARE(int CoNotInParallel,(UBYTE *))
DECLARE(int DoInParallel,(UBYTE *,int))
DECLARE(int CoEndInExpression,(UBYTE *))
DECLARE(int CoBracket,(UBYTE *))
DECLARE(int CoCFunction,(UBYTE *))
DECLARE(int CoCTensor,(UBYTE *))
DECLARE(int CoCollect,(UBYTE *))
DECLARE(int CoCompress,(UBYTE *))
DECLARE(int CoContract,(UBYTE *))
DECLARE(int CoCycleSymmetrize,(UBYTE *))
DECLARE(int CoDelete,(UBYTE *))
DECLARE(int CoTableBase,(UBYTE *))
DECLARE(int CoApply,(UBYTE *))
DECLARE(int CoDenominators,(UBYTE *))
DECLARE(int CoDimension,(UBYTE *))
DECLARE(int CoDiscard,(UBYTE *))
DECLARE(int CoDisorder,(UBYTE *))
DECLARE(int CoDrop,(UBYTE *))
DECLARE(int CoElse,(UBYTE *))
DECLARE(int CoElseIf,(UBYTE *))
DECLARE(int CoEndArgument,(UBYTE *))
DECLARE(int CoEndInside,(UBYTE *))
DECLARE(int CoEndIf,(UBYTE *))
DECLARE(int CoEndRepeat,(UBYTE *))
DECLARE(int CoEndTerm,(UBYTE *))
DECLARE(int CoEndWhile,(UBYTE *))
DECLARE(int CoExit,(UBYTE *))
DECLARE(int CoFactArg,(UBYTE *))
DECLARE(int CoFill,(UBYTE *))
DECLARE(int CoFillExpression,(UBYTE *))
DECLARE(int CoFixIndex,(UBYTE *))
DECLARE(int CoFormat,(UBYTE *))
DECLARE(int CoGlobal,(UBYTE *))
DECLARE(int CoGoTo,(UBYTE *))
DECLARE(int CoId,(UBYTE *))
DECLARE(int CoIdNew,(UBYTE *))
DECLARE(int CoIdOld,(UBYTE *))
DECLARE(int CoIf,(UBYTE *))
DECLARE(int CoIfMatch,(UBYTE *))
DECLARE(int CoIndex,(UBYTE *))
DECLARE(int CoInsideFirst,(UBYTE *))
DECLARE(int CoKeep,(UBYTE *))
DECLARE(int CoLabel,(UBYTE *))
DECLARE(int CoLoad,(UBYTE *))
DECLARE(int CoLocal,(UBYTE *))
DECLARE(int CoMany,(UBYTE *))
DECLARE(int CoMerge,(UBYTE *))
DECLARE(int CoMetric,(UBYTE *))
DECLARE(int CoModOption,(UBYTE *))
DECLARE(int CoModuleOption,(UBYTE *))
DECLARE(int CoModulusGCD,(UBYTE *))
DECLARE(int CoModulus,(UBYTE *))
DECLARE(int CoMulti,(UBYTE *))
DECLARE(int CoMultiply,(UBYTE *))
DECLARE(int CoNFunction,(UBYTE *))
DECLARE(int CoNPrint,(UBYTE *))
DECLARE(int CoNTensor,(UBYTE *))
DECLARE(int CoNWrite,(UBYTE *))
DECLARE(int CoNoDrop,(UBYTE *))
DECLARE(int CoNoSkip,(UBYTE *))
DECLARE(int CoNormalize,(UBYTE *))
DECLARE(int CoMakeInteger,(UBYTE *))
DECLARE(int CoOff,(UBYTE *))
DECLARE(int CoOn,(UBYTE *))
DECLARE(int CoOnce,(UBYTE *))
DECLARE(int CoOnly,(UBYTE *))
DECLARE(int CoPolyFun,(UBYTE *))
DECLARE(int CoPolyRatFun,(UBYTE *))
DECLARE(int CoPolyNorm,(UBYTE *))
DECLARE(int CoPrint,(UBYTE *))
DECLARE(int CoPrintB,(UBYTE *))
DECLARE(int CoProperCount,(UBYTE *))
DECLARE(int CoUnitTrace,(UBYTE *))
DECLARE(int CoRCycleSymmetrize,(UBYTE *))
DECLARE(int CoRatio,(UBYTE *))
DECLARE(int CoRedefine,(UBYTE *))
DECLARE(int CoRenumber,(UBYTE *))
DECLARE(int CoRepeat,(UBYTE *))
DECLARE(int CoSave,(UBYTE *))
DECLARE(int CoSelect,(UBYTE *))
DECLARE(int CoSet,(UBYTE *))
DECLARE(int CoSetExitFlag,(UBYTE *))
DECLARE(int CoSkip,(UBYTE *))
DECLARE(int CoSlavePatch,(UBYTE *))
DECLARE(int CoPushHide,(UBYTE *))
DECLARE(int CoPopHide,(UBYTE *))
DECLARE(int CoHide,(UBYTE *))
DECLARE(int CoNoHide,(UBYTE *))
DECLARE(int CoUnHide,(UBYTE *))
DECLARE(int CoNoUnHide,(UBYTE *))
DECLARE(int CoSort,(UBYTE *))
DECLARE(int CoSplitArg,(UBYTE *))
DECLARE(int CoSplitFirstArg,(UBYTE *))
DECLARE(int CoSplitLastArg,(UBYTE *))
DECLARE(int CoSum,(UBYTE *))
DECLARE(int CoSymbol,(UBYTE *))
DECLARE(int CoSymmetrize,(UBYTE *))
DECLARE(int DoTable,(UBYTE *,int))
DECLARE(int CoTable,(UBYTE *))
DECLARE(int CoTerm,(UBYTE *))
DECLARE(int CoNTable,(UBYTE *))
DECLARE(int CoCTable,(UBYTE *))
DECLARE(int CoToTensor,(UBYTE *))
DECLARE(int CoToVector,(UBYTE *))
DECLARE(int CoTrace4,(UBYTE *))
DECLARE(int CoTraceN,(UBYTE *))
DECLARE(int CoChisholm,(UBYTE *))
DECLARE(int CoClearTable,(UBYTE *))
DECLARE(int DoChain,(UBYTE *,int))
DECLARE(int CoChainin,(UBYTE *))
DECLARE(int CoChainout,(UBYTE *))
DECLARE(int CoTryReplace,(UBYTE *))
DECLARE(int CoVector,(UBYTE *))
DECLARE(int CoWhile,(UBYTE *))
DECLARE(int CoWrite,(UBYTE *))
DECLARE(int CoAuto,(UBYTE *))
DECLARE(int CoTBaddto,(UBYTE *))
DECLARE(int CoTBaudit,(UBYTE *))
DECLARE(int CoTBcleanup,(UBYTE *))
DECLARE(int CoTBcreate,(UBYTE *))
DECLARE(int CoTBenter,(UBYTE *))
DECLARE(int CoTBhelp,(UBYTE *))
DECLARE(int CoTBload,(UBYTE *))
DECLARE(int CoTBoff,(UBYTE *))
DECLARE(int CoTBon,(UBYTE *))
DECLARE(int CoTBopen,(UBYTE *))
DECLARE(int CoTBreplace,(UBYTE *))
DECLARE(int CoTBuse,(UBYTE *))
DECLARE(int CoTestUse,(UBYTE *))
DECLARE(int CoThreadBucket,(UBYTE *))
DECLARE(int AddComString,(int,WORD *,UBYTE *,int))
DECLARE(int CompileAlgebra,(UBYTE *,int,WORD *))
DECLARE(int IsIdStatement,(UBYTE *))
DECLARE(UBYTE *IsRHS,(UBYTE *,UBYTE))
DECLARE(int ParenthesesTest,(UBYTE *))
DECLARE(int tokenize,(UBYTE *,WORD))
DECLARE(void WriteTokens,(SBYTE *))
DECLARE(int simp1token,(SBYTE *))
DECLARE(int simpwtoken,(SBYTE *))
DECLARE(int simp2token,(SBYTE *))
DECLARE(int simp3atoken,(SBYTE *,int))
DECLARE(int simp3btoken,(SBYTE *,int))
DECLARE(int simp4token,(SBYTE *))
DECLARE(int simp5token,(SBYTE *,int))
DECLARE(UBYTE *SkipAName,(UBYTE *))
DECLARE(int TestTables,ARG0)
DECLARE(int GetLabel,(UBYTE *))
DECLARE(int CoIdExpression,(UBYTE *,int))
DECLARE(int CoAssign,(UBYTE *))
DECLARE(int DoExpr,(UBYTE *,int))
DECLARE(int CompileSubExpressions,(SBYTE *))
DECLARE(int CodeGenerator,(SBYTE *))
DECLARE(int CompleteTerm,(WORD *,UWORD *,UWORD *,WORD,WORD,int))
DECLARE(int InsTree,(int))
DECLARE(void RedoTree,(CBUF *,int))
DECLARE(void ClearTree,(int))
DECLARE(int CatchDollar,(int))
DECLARE(int AssignDollar,(WORD *,WORD))
DECLARE(UBYTE *WriteDollarToBuffer,(WORD,WORD))
DECLARE(void AddToDollarBuffer,(UBYTE *))
DECLARE(void TermAssign,(WORD *))
DECLARE(void WildDollars,ARG0)
DECLARE(LONG numcommute,(WORD *,LONG *))
DECLARE(int FullRenumber,(WORD *,WORD))
DECLARE(int Lus,(WORD *,WORD,WORD,WORD,WORD,WORD))
DECLARE(int FindLus,(int,int,int))
DECLARE(int CoReplaceLoop,(UBYTE *))
DECLARE(int CoFindLoop,(UBYTE *))
DECLARE(int DoFindLoop,(UBYTE *,int))
DECLARE(int CoFunPowers,(UBYTE *))
DECLARE(int SortTheList,(int *,int))
DECLARE(int MatchIsPossible,(WORD *,WORD *))
DECLARE(void StudyPattern,(WORD *))
DECLARE(WORD DolToTensor,(WORD))
DECLARE(WORD DolToFunction,(WORD))
DECLARE(WORD DolToVector,(WORD))
DECLARE(WORD DolToNumber,(WORD))
DECLARE(WORD DolToSymbol,(WORD))
DECLARE(WORD DolToIndex,(WORD))
DECLARE(int CoPrintTable,(UBYTE *))
DECLARE(int CoDeallocateTable,(UBYTE *))
 
DECLARE(int Optimize,(WORD))
DECLARE(int LoadOpti,(WORD))
DECLARE(int PutObject,(WORD *,int))
DECLARE(void CleanOptiBuffer,ARG0)
DECLARE(int PrintOptima,(WORD))
DECLARE(int FindScratchName,ARG0)
DECLARE(WORD MaxPowerOpti,(LONG))
DECLARE(WORD HuntNumFactor,(LONG,WORD *,int))
DECLARE(WORD HuntFactor,(LONG,WORD *,int))
DECLARE(void HuntPairs,(LONG,WORD))
DECLARE(void HuntBrackets,(LONG))
DECLARE(int AddToOpti,(WORD *,int))
DECLARE(LONG TestNewSca,(LONG,WORD *,WORD *))
DECLARE(void NormOpti,(WORD *))
DECLARE(void SortOpti,(LONG))
DECLARE(void SplitOpti,(WORD **,LONG))
DECLARE(void CombiOpti,ARG0)
DECLARE(int TakeLongRoot,(UWORD *,WORD *,WORD))
DECLARE(int TakeRatRoot,(UWORD *,WORD *,WORD))
DECLARE(void HuntPowers,(LONG,WORD))
DECLARE(void HuntNumBrackets,(LONG))
DECLARE(void ClearTableTree,(TABLES))
DECLARE(int InsTableTree,(TABLES,WORD *))
DECLARE(void RedoTableTree,(TABLES,int))
DECLARE(int FindTableTree,(TABLES,WORD *,int))
DECLARE(void finishcbuf,(WORD))
DECLARE(void clearcbuf,(WORD))
DECLARE(void CleanUpSort,(int))
DECLARE(FILEHANDLE *AllocFileHandle,ARG0)
DECLARE(VOID DeAllocFileHandle,(FILEHANDLE *))
DECLARE(VOID LowerSortLevel,ARG0)
DECLARE(int InsideDollar,(WORD *,WORD))
DECLARE(DOLLARS DolToTerms,(WORD))
DECLARE(int SetExprCases,(int,int,int))
DECLARE(int TestSelect,(WORD *,WORD *))
DECLARE(int MakeSetupAllocs,ARG0)
DECLARE(int TryFileSetups,ARG0)
DECLARE(void ExchangeExpressions,(int,int))
DECLARE(void ExchangeDollars,(int,int))
DECLARE(int GetFirstBracket,(WORD *,int))
DECLARE(UBYTE *PreIfDollarEval,(UBYTE *,int *))
DECLARE(LONG TermsInDollar,(WORD))
DECLARE(LONG TermsInExpression,(WORD))
DECLARE(WORD *TranslateExpression,(UBYTE *))
DECLARE(int IsSetMember,(WORD *,WORD))
DECLARE(int IsMultipleOf,(WORD *,WORD *))
DECLARE(int TwoExprCompare,(WORD *,WORD *,int))
DECLARE(void UpdatePositions,ARG0)
DECLARE(void M_check,ARG0)
DECLARE(void M_print,ARG0)
DECLARE(void M_check1,ARG0)
DECLARE(void PrintTime,ARG0)
DECLARE(WORD *PolynoAdd,(WORD *,WORD *))
DECLARE(WORD *PolynoSub,(WORD *,WORD *))
DECLARE(WORD *PolynoMul,(WORD *,WORD *))
DECLARE(WORD *PolynoDiv,(WORD *,WORD *,WORD **))
DECLARE(WORD *Polyno1Div,(WORD *,WORD *,WORD **))
DECLARE(WORD *PolynoGCD,(WORD *,WORD *))
DECLARE(WORD *Polyno1GCD,(WORD *,WORD *))
DECLARE(UBYTE *PolynoPrint,(WORD *))
DECLARE(int PolynoWrite,(WORD *))
DECLARE(WORD *PolynoNormalize,(WORD *))
DECLARE(WORD *PolynoUnify,(WORD *,int))
DECLARE(WORD *PolynoIntFac,(WORD *))
DECLARE(void PolynoPushBracket,(WORD))
DECLARE(void PolynoPopBracket,ARG0)
DECLARE(void PolynoStart,ARG0)
DECLARE(void PolynoFinish,ARG0)
DECLARE(WORD DoPolynomial,(WORD *,WORD))
DECLARE(WORD DoPolyGetRem,(WORD *,WORD))
DECLARE(WORD *CopyOfPolynomial,(WORD *))
DECLARE(WORD *PolynoCoefNorm,(WORD *,WORD,WORD **,int))
DECLARE(WORD *MakePolynomial,(WORD,int,int *))
DECLARE(int DoPolynoNorm,(int,WORD,WORD,WORD))
/*
DECLARE(int IsProductOf,(WORD *,WORD *))
*/
DECLARE(POSITION *FindBracket,(EXPRESSIONS,WORD *))
DECLARE(VOID PutBracketInIndex,(WORD *,POSITION *))
DECLARE(void ClearBracketIndex,(WORD))
DECLARE(VOID OpenBracketIndex,(WORD))
DECLARE(int DoNoParallel,(UBYTE *))
DECLARE(int DoParallel,(UBYTE *))
DECLARE(int DoModSum,(UBYTE *))
DECLARE(int DoModMax,(UBYTE *))
DECLARE(int DoModMin,(UBYTE *))
DECLARE(int DoModLocal,(UBYTE *))
DECLARE(UBYTE *DoModDollar,(UBYTE *,int))
DECLARE(int DoSlavePatch,(UBYTE *))
DECLARE(int DoinParallel,(UBYTE *))
DECLARE(int DonotinParallel,(UBYTE *))

DECLARE(int FlipTable,(FUNCTIONS,int))
DECLARE(int ChainIn,(WORD *,WORD))
DECLARE(int ChainOut,(WORD *,WORD))
DECLARE(int PolyNorm,(PHEAD WORD *,WORD,WORD,WORD))
DECLARE(int ArgumentImplode,(PHEAD WORD *,WORD *))
DECLARE(int ArgumentExplode,(PHEAD WORD *,WORD *))
DECLARE(int DenToFunction,(WORD *,WORD))
 
DECLARE(WORD ReadElIf,ARG0)
DECLARE(WORD HowMany,(WORD *,WORD *))
DECLARE(VOID RemoveDollars,ARG0)
DECLARE(LONG CountTerms1,(PHEAD0))
DECLARE(LONG TermsInBracket,(PHEAD WORD *,WORD))
DECLARE(int Crash,ARG0)

void *mmalloc(size_t size,char *message);
char *str_dup(char *str);
void convertblock(INDEXBLOCK *in,INDEXBLOCK *out,int mode);
void convertnamesblock(NAMESBLOCK *in,NAMESBLOCK *out,int mode);
void convertiniinfo(INIINFO *in,INIINFO *out,int mode);
int ReadIndex(DBASE *d);
int WriteIndexBlock(DBASE *d,MLONG num);
int WriteNamesBlock(DBASE *d,MLONG num);
int WriteIndex(DBASE *d);
int WriteIniInfo(DBASE *d);
int ReadIniInfo(DBASE *d);
int AddToIndex(DBASE *d,MLONG number);
DBASE *GetDbase(char *filename);
DBASE *OpenDbase(char *filename);
char *ReadObject(DBASE *d,MLONG tablenumber,char *arguments);
char *ReadijObject(DBASE *d,MLONG i,MLONG j,char *arguments);
int ExistsObject(DBASE *d,MLONG tablenumber,char *arguments);
int DeleteObject(DBASE *d,MLONG tablenumber,char *arguments);
char *GetSubString(char *keyword,char **argv);
int WriteObject(DBASE *d,MLONG tablenumber,char *arguments,char *rhs,MLONG number);
MLONG AddObject(DBASE *d,MLONG tablenumber,char *arguments,char *rhs);
int Cleanup(DBASE *d);
DBASE *NewDbase(char *name,MLONG number);
void FreeTableBase(DBASE *d);
int ComposeTableNames(DBASE *d);
int PutTableNames(DBASE *d);
MLONG AddTableName(DBASE *d,char *name,TABLES T);
MLONG GetTableName(DBASE *d,char *name);
MLONG FindTableNumber(DBASE *d,char *name);
int TouchKey(DBASE *d,char *key,char *value);
int DumpContents(DBASE *d,char *filename,MLONG from,MLONG to);
int RunMake(int variety,char **inargv,char ***outargv,MLONG num,char *outvar);
int handlefold(DBASE *d,char *start,char *finish,char *name,char *varname);
int SumStart(int variety,char *outname);
int SumStep(int variety,char **argv,MLONG num,char *outname);
int SpecStep(int variety,char **argv1,char **argv2,MLONG num,char *outname);
int SumFinish(int variety,char *outname);
int LinSumStart(int variety,char *outname);
int LinSumStep(int variety,char **argv,MLONG num,char *outname);
int LinSumDecl(int variety,char **argv,MLONG num,char *outname);
int LinSumFinish(int variety,char *outname);
char *SkipString(char *);
int ModulusGCD1(WORD modu,WORD fun1,WORD fun2,WORD *term,WORD sym);
int MakeMono(WORD modu,WORD *t,WORD whichbuffer,WORD sym);
int TryEnvironment(VOID);

#ifdef WITHZLIB
DECLARE(int SetupOutputGZIP,(FILEHANDLE *))
DECLARE(int PutOutputGZIP,(FILEHANDLE *))
DECLARE(int FlushOutputGZIP,(FILEHANDLE *))
DECLARE(int SetupAllInputGZIP,(SORTING *))
DECLARE(int SetupInputGZIP,(FILEHANDLE *,int))
DECLARE(LONG GetInputGZIP,(FILEHANDLE *,int))
DECLARE(LONG FillInputGZIP,(FILEHANDLE *,POSITION *,UBYTE *,LONG,int))
#endif

#ifdef WITHPTHREADS
DECLARE(VOID BeginIdentities,ARG0)
DECLARE(int WhoAmI,ARG0)
DECLARE(int StartAllThreads,(int))
DECLARE(void StartHandleLock,ARG0)
DECLARE(VOID TerminateAllThreads,ARG0)
DECLARE(int GetAvailableThread,ARG0)
DECLARE(int ConditionalGetAvailableThread,ARG0)
DECLARE(int BalanceRunThread,(PHEAD int,WORD *,WORD))
DECLARE(void WakeupThread,(int,int))
DECLARE(int MasterWait,ARG0)
DECLARE(int InParallelProcessor,ARG0)
DECLARE(int ThreadsProcessor,(EXPRESSIONS,WORD))
DECLARE(int ThreadsMerge,ARG0)
DECLARE(int MasterMerge,ARG0)
DECLARE(int PutToMaster,(PHEAD WORD *))
DECLARE(void SetWorkerFiles,ARG0)
DECLARE(int MakeThreadBuckets,(int,int))
DECLARE(void Test,ARG0)
DECLARE(int SendOneBucket,ARG0)
DECLARE(int LoadOneThread,(int,int,THREADBUCKET *,int))
DECLARE(void *RunSortBot,(void *))
DECLARE(void MasterWaitAllSortBots,ARG0)
DECLARE(int SortBotMerge,(PHEAD0))
DECLARE(int SortBotOut,(PHEAD WORD *))
DECLARE(void DefineSortBotTree,ARG0)
DECLARE(int SortBotMasterMerge,ARG0)
DECLARE(int SortBotWait,(int))
DECLARE(void StartIdentity,ARG0)
DECLARE(void FinishIdentity,(void *))
DECLARE(int SetIdentity,(int *))
DECLARE(ALLPRIVATES *InitializeOneThread,(int))
DECLARE(void FinalizeOneThread,(int))
DECLARE(void *RunThread,(void *))
DECLARE(void IAmAvailable,(int))
DECLARE(int ThreadWait,(int))
DECLARE(int ThreadClaimedBlock,(int))
DECLARE(int GetThread,(int))
DECLARE(int UpdateOneThread,(int))
DECLARE(void AlsoAvailable,(int))
DECLARE(void AlsoRunning,(int))
DECLARE(void MasterWaitAll,ARG0)
DECLARE(void MasterWaitAllBlocks,ARG0)
DECLARE(int MasterWaitThread,(int))
DECLARE(void WakeupMasterFromThread,(int,int))
DECLARE(int LoadReadjusted,ARG0)
DECLARE(int IniSortBlocks,(int))

#endif

DECLARE(int CopyExpression,(FILEHANDLE *,FILEHANDLE *))

/*[12dec2003 mt]:*/
DECLARE(int set_in,(UBYTE, set_of_char))
DECLARE(one_byte set_set,(UBYTE, set_of_char))
DECLARE(one_byte set_del,(UBYTE, set_of_char))
DECLARE(one_byte set_sub, (set_of_char, set_of_char, set_of_char))
DECLARE(int DoPreAddSeparator,(UBYTE *))
DECLARE(int DoPreRmSeparator,(UBYTE *))
/*:[12dec2003 mt]*/

/*[14apr2004 mt]:*/
/*See the file extcmd.c*/
/*[08may2006 mt]:*/
/*
DECLARE(int openExternalChannel,(char *))
*/
DECLARE(int openExternalChannel,(UBYTE *,int,UBYTE *,UBYTE *))
DECLARE(int initPresetExternalChannels,(UBYTE *, int))
/*:[08may2006 mt]*/
DECLARE(int closeExternalChannel,(int))
DECLARE(int selectExternalChannel,(int))
DECLARE(int getCurrentExternalChannel,(VOID))
DECLARE(VOID closeAllExternalChannels,(VOID))
/*:[14apr2004 mt]*/

/*[08may2006 mt]:*/
/*DECLARE(int writexactly,(int,char *,size_t))*/
/*:[08may2006 mt]*/

/*[17nov2005 mt]:*/
DECLARE(typedef int (*WRITEBUFTOEXTCHANNEL),(char *,size_t) )
DECLARE(typedef int (*GETCFROMEXTCHANNEL),() )
DECLARE(typedef int (*SETTERMINATORFOREXTERNALCHANNEL),(char *) )
/*[08may2006 mt]:*/
DECLARE(typedef int (*SETKILLMODEFOREXTERNALCHANNEL),(int,int) )
/*:[08may2006 mt]*/
DECLARE(typedef LONG (*WRITEFILE), (int,UBYTE *,LONG) )
DECLARE(typedef WORD (*COMPARE), (PHEAD WORD *,WORD *,WORD) )

#define Compare ((COMPARE)AR.CompareRoutine)

#ifdef PARALLEL
DECLARE(LONG PF_BroadcastNumberOfTerms,(LONG))
DECLARE(int PF_Processor,(EXPRESSIONS,WORD,WORD))

#endif

DECLARE(UBYTE *defineChannel,(UBYTE*, HANDLERS*))
DECLARE(int writeToChannel,(int,UBYTE *,HANDLERS*))
#ifdef WITHEXTERNALCHANNEL
DECLARE(LONG WriteToExternalChannel,(int,UBYTE *,LONG))
#endif
DECLARE(pid_t getExternalChannelPid,ARG0)
DECLARE(int writeBufToExtChannelOk,(char *,size_t))
DECLARE(int getcFromExtChannelOk,ARG0)
DECLARE(int setKillModeForExternalChannelOk,(int,int))
DECLARE(int setTerminatorForExternalChannelOk,(char *))
DECLARE(int getcFromExtChannelFailure,ARG0)
DECLARE(int setKillModeForExternalChannelFailure,(int,int))
DECLARE(int setTerminatorForExternalChannelFailure,(char *))
DECLARE(int writeBufToExtChannelFailure,(char *,size_t))

DECLARE(int ReleaseTB,ARG0)

DECLARE(int SymbolNormalize,(WORD *,WORD *,WORD))
DECLARE(int CheckMinTerm,(WORD *,WORD *))
DECLARE(int ReOrderSymbols,(WORD *,WORD *,WORD))
DECLARE(int CompareSymbols,(PHEAD WORD *,WORD *,WORD))
DECLARE(WORD *PolyAdd,(PHEAD WORD *,WORD *))
DECLARE(WORD *PolyMul,(PHEAD WORD *,WORD *))
DECLARE(WORD *PolyDiv,(PHEAD WORD *,WORD *))
DECLARE(WORD *PolyDivI,(PHEAD WORD *,WORD *))
DECLARE(WORD *PolyMul0,(PHEAD WORD *,WORD *))
DECLARE(WORD *PolyDiv0,(PHEAD WORD *,WORD *))
DECLARE(WORD *PolyRatNorm,(PHEAD WORD *,WORD *))
DECLARE(WORD *PolyFunNorm,(PHEAD WORD *,WORD))
DECLARE(WORD *PolyFunAddRat,(PHEAD WORD *,WORD *))
DECLARE(WORD *PolyRemoveContent,(PHEAD WORD *,WORD))
DECLARE(WORD *PolyGCD,(PHEAD WORD *,WORD *))
DECLARE(WORD *PolyGCD1,(PHEAD WORD *,WORD *))
DECLARE(WORD *PolyGCD1a,(PHEAD WORD *,WORD *))
DECLARE(WORD *PolyGCD1b,(PHEAD WORD *,WORD *))
DECLARE(WORD *PolyGCD1c,(PHEAD WORD *,WORD *))
DECLARE(WORD *PolyGCD1d,(PHEAD WORD *,WORD *))
DECLARE(WORD *PolyDiv1,(PHEAD WORD *,WORD *))
DECLARE(WORD *PolyDiv1d,(PHEAD WORD *,WORD *))
DECLARE(WORD *PolyPseudoRem1,(PHEAD WORD *,WORD *))
DECLARE(WORD *GetNegPow,(PHEAD WORD *))
DECLARE(WORD *PolyNormPoly,(PHEAD WORD *))
DECLARE(WORD PolyRatFunMul,(PHEAD WORD *))
DECLARE(WORD *PolyTake,(PHEAD WORD *,WORD))
DECLARE(WORD PolyGetRenumbering,(PHEAD WORD *,WORD *))
DECLARE(WORD InvertModular,(WORD,WORD))
DECLARE(WORD InvertLongModular,(PHEAD UWORD *,WORD,WORD,UWORD *,WORD *))
/*DECLARE(WORD *PolyModGCD,(PHEAD WORD *,WORD *,WORD))*/
DECLARE(int PolyModGCD,(POLYMOD *,POLYMOD *))
DECLARE(int PolyConvertToModulus,(WORD *,POLYMOD *,WORD))
DECLARE(WORD *PolyConvertFromModulus,(PHEAD POLYMOD *,WORD))
DECLARE(WORD *PolyChineseRemainder,(PHEAD WORD *,WORD *,WORD *,WORD,WORD))
DECLARE(WORD NextPrime,(PHEAD WORD))
DECLARE(WORD ModShortPrime,(UWORD *,WORD,WORD))
DECLARE(int AllocPolyModCoefs,(POLYMOD *,WORD))
DECLARE(WORD DivMod,(UWORD *,WORD,WORD))
DECLARE(int AccumTermGCD,(WORD *,WORD *))
DECLARE(int PolyTakeSqrt,(PHEAD WORD *))
DECLARE(int PolyTakeRoot,(PHEAD WORD *,WORD))
DECLARE(WORD *PolyPow,(PHEAD WORD *,WORD))
DECLARE(WORD *PolyInterpolation,(PHEAD WORD *,WORD *,WORD))
DECLARE(WORD *PolySubs,(PHEAD WORD *,WORD,WORD))
DECLARE(WORD *PolyNewton,(PHEAD WORD **,WORD,WORD))
DECLARE(WORD *PolyGetNewtonCoef,(PHEAD WORD **,WORD))
DECLARE(WORD ModPow,(WORD,WORD,WORD))
DECLARE(WORD PolyModSubsVector,(PHEAD WORD *,WORD *,WORD,WORD,WORD,WORD,POLYMOD *))
DECLARE(WORD *PolyGetSymbols,(PHEAD WORD *,int *))
DECLARE(WORD *PolyGetGCDPowers,(PHEAD WORD *,WORD *,WORD *,WORD *))
DECLARE(WORD *PolyGetConfig,(PHEAD WORD))
DECLARE(WORD wranf,(PHEAD0))

DECLARE(WORD *EvaluateGcd,(PHEAD WORD *))

DECLARE(WORD ReadSaveHeader,ARG0)
DECLARE(WORD ReadSaveIndex,(FILEINDEX *))
DECLARE(WORD ReadSaveExpression,(UBYTE *,UBYTE *,LONG *,LONG *))
DECLARE(UBYTE *ReadSaveTerm32,(UBYTE *,UBYTE *,UBYTE **,UBYTE *,UBYTE *,int))
DECLARE(WORD ReadSaveVariables,(UBYTE *,UBYTE *,LONG *,LONG *,INDEXENTRY *,LONG *))
DECLARE(WORD WriteStoreHeader,(WORD))

DECLARE(int CheckRecoveryFile,ARG0)
DECLARE(char *RecoveryFilename,ARG0)
DECLARE(int DoRecovery,(PHEAD0))
DECLARE(void DoCheckpoint,(PHEAD0))

/*
  	#] Declarations : 
*/
#endif
