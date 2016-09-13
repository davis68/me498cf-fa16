/*
 *
 * Copyright 2003-2011 ANSYS, Inc.
 * All Rights Reserved
 */

#define UDF_COMPILER 1

#define EOF (-1)
#define NULL (0)

#define const
#define register


typedef unsigned long size_t;



/* config.h */

#define RP_2D 1
#define RP_3D 0
#define RP_HOST 0
#define RP_NODE 0
#define RP_DOUBLE 0
#define RP_NETWORK 1

#define STRUCT_OFF(t,offset,type)((type*)((char *)(t)+offset))
#define STRUCT_REF(t,offset,type)(*STRUCT_OFF(t,offset,type))

#define DOMAIN_C(t)STRUCT_REF(t,0,Thread *)
#define DOMAIN_NOSOLVE_C(t)STRUCT_REF(t,8,Thread *)
#define DOMAIN_NOSOLVE_EXT_C(t)STRUCT_REF(t,16,Thread *)
#define DOMAIN_F(t)STRUCT_REF(t,24,Thread *)
#define DOMAIN_NOSOLVE_F(t)STRUCT_REF(t,32,Thread *)
#define DOMAIN_ID(t)STRUCT_REF(t,2112,int)
#define PHASE_DOMAIN_INDEX(t)STRUCT_REF(t,2116,int)
#define DOMAIN_N_DOMAINS(t)STRUCT_REF(t,2124,int)
#define DOMAIN_SUPER_DOMAIN(t)STRUCT_REF(t,2304,Domain *)
#define DOMAIN_SUB_DOMAIN(t,i)(STRUCT_OFF(t,2128,Domain *)[i])

#define THREAD_STORE(t,nv)(STRUCT_OFF(t,52408,struct store_struct *)[nv])
#define THREAD_STORAGE(t,nv)(STRUCT_OFF(t,808,void *)[nv])
#define THREAD_T0(t)STRUCT_REF(t,344,Thread *)
#define THREAD_T1(t)STRUCT_REF(t,352,Thread *)
#define THREAD_NEXT(t)STRUCT_REF(t,464,Thread *)
#define THREAD_SHADOW(t)STRUCT_REF(t,472,Thread *)
#define THREAD_ID(t)STRUCT_REF(t,752,int)
#define THREAD_NAME(t)STRUCT_REF(t,72,char *)
#define THREAD_N_ELEMENTS(t)STRUCT_REF(t,332,int)
#define THREAD_FLAGS(t)STRUCT_REF(t,756,int)
#define THREAD_SUB_THREAD(t,i)(STRUCT_OFF(t,552,Thread *)[i])
#define THREAD_SUB_THREADS(t)STRUCT_OFF(t,552,Thread *)
#define THREAD_SUPER_THREAD(t)STRUCT_REF(t,528,Thread *)
#define THREAD_DOMAIN(t)STRUCT_REF(t,800,Domain *)
#define THREAD_HEAD(t)STRUCT_REF(t,0,Thread_Head *)
#define THREAD_MATERIAL(t)(STRUCT_REF(THREAD_HEAD(t),135048,Material *))

#define NODE_COORD(v)STRUCT_OFF(v,24,real)

#define P_INIT_DIAM(p)STRUCT_REF(p,368,real)
#define P_INIT_MASS(p)STRUCT_REF(p,376,real)
#define P_INIT_RHO(p)STRUCT_REF(p,372,real)
#define P_INIT_TEMP(p)STRUCT_REF(p,380,real)
#define P_INIT_LMF(p)STRUCT_REF(p,388,real)
#define P_VF(p)STRUCT_REF(p,1376,real)
#define P_CF(p)STRUCT_REF(p,1380,real)
#define P_VFF(p)STRUCT_REF(p,1384,real)
#define P_DF(p)STRUCT_REF(p,1388,real)
#define P_DT(p)STRUCT_REF(p,60,real)
#define P_DIAM(p)STRUCT_REF(p,464,real)
#define P_T(p)STRUCT_REF(p,476,real)
#define P_VEL(p)STRUCT_OFF(p,452,real)
#define P_RHO(p)STRUCT_REF(p,468,real)
#define P_LMF(p)STRUCT_REF(p,484,real)
#define P_MASS(p)STRUCT_REF(p,472,real)
#define P_TIME(p)STRUCT_REF(p,480,real)
#define P_DIAM0(p)STRUCT_REF(p,416,real)
#define P_VEL0(p)STRUCT_OFF(p,404,real)
#define P_T0(p)STRUCT_REF(p,428,real)
#define P_RHO0(p)STRUCT_REF(p,420,real)
#define P_LMF0(p)STRUCT_REF(p,436,real)
#define P_MASS0(p)STRUCT_REF(p,424,real)
#define P_TIME0(p)STRUCT_REF(p,432,real)
#define P_CURRENT_LAW_INDEX(p)STRUCT_REF(p,248,int)
#define P_INJECTION(p)STRUCT_REF(p,328,Injection *)
#define P_EVAP_SPECIES_INDEX(p)STRUCT_REF(P_INJECTION(p),3120,int)
#define P_DEVOL_SPECIES_INDEX(p)STRUCT_REF(P_INJECTION(p),3124,int)
#define P_OXID_SPECIES_INDEX(p)STRUCT_REF(P_INJECTION(p),3128,int)
#define P_PROD_SPECIES_INDEX(p)STRUCT_REF(P_INJECTION(p),3132,int)
#define P_LAWS(p,in)STRUCT_OFF(P_INJECTION(p),164,int)[in]

typedef char UDF_Cache_Data[48];

#define MATERIAL_PROPERTY(m)STRUCT_OFF(m,128,Property)
#define PROPERTY_LENGTH 144
#define MATERIAL_PROPERTY_ELEMENT(m,i)((Property *)((char *)MATERIAL_PROPERTY(m)+PROPERTY_LENGTH*i))
#define MATERIAL_PROP(m,i)(STRUCT_REF(MATERIAL_PROPERTY_ELEMENT(m,i),4,float))

#define NW_CELL(n) STRUCT_REF(((char *)network+n*24),16,Network_cell *) 
#define NWC_T(n,c) STRUCT_REF(((char *)NW_CELL(n)+c*360),200,real) 
#define NWE_T(e) STRUCT_REF(((char *)nw_end + e*252),4,real)
