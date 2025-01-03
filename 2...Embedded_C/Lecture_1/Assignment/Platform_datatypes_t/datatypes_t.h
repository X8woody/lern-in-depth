#ifndef DT_H_
#define DT_H_


/* -----------------non_volatile data_types-------------------*/

typedef char  							char_t;

typedef unsigned char 					uint8_t;
typedef signed char   					int8_t;

typedef signed short    				int16_t;
typedef unsigned short    				uint16_t;

typedef signed int 			    		int32_t;
typedef unsigned int    				uint32_t;

typedef signed long long    			int64_t;
typedef unsigned long long    			uint64_t;

/* -----------------volatile data_types-------------------*/

typedef volatile char  				    vchar_t;

typedef volatile unsigned char 			vuint8_t;
typedef volatile signed char   			vint8_t;

typedef volatile signed short    		vint16_t;
typedef volatile unsigned short    		vuint16_t;

typedef volatile signed int 			vint32_t;
typedef volatile unsigned int    		vuint32_t;

typedef volatile signed long long    	vint64_t;
typedef volatile unsigned long long    	vuint64_t;

#endif