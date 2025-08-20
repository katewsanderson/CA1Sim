/* Created by Language version: 7.7.0 */
/* VECTORIZED */
#define NRN_VECTORIZED 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mech_api.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__Ca
#define _nrn_initial _nrn_initial__Ca
#define nrn_cur _nrn_cur__Ca
#define _nrn_current _nrn_current__Ca
#define nrn_jacob _nrn_jacob__Ca
#define nrn_state _nrn_state__Ca
#define _net_receive _net_receive__Ca 
#define state state__Ca 
 
#define _threadargscomma_ _p, _ppvar, _thread, _nt,
#define _threadargsprotocomma_ double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt,
#define _threadargs_ _p, _ppvar, _thread, _nt
#define _threadargsproto_ double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 /* Thread safe. No static _p or _ppvar. */
 
#define t _nt->_t
#define dt _nt->_dt
#define gtcabar _p[0]
#define gtcabar_columnindex 0
#define gncabar _p[1]
#define gncabar_columnindex 1
#define glcabar _p[2]
#define glcabar_columnindex 2
#define gcamult _p[3]
#define gcamult_columnindex 3
#define i _p[4]
#define i_columnindex 4
#define gtca _p[5]
#define gtca_columnindex 5
#define gnca _p[6]
#define gnca_columnindex 6
#define glca _p[7]
#define glca_columnindex 7
#define gbar _p[8]
#define gbar_columnindex 8
#define taua _p[9]
#define taua_columnindex 9
#define ainf _p[10]
#define ainf_columnindex 10
#define taub _p[11]
#define taub_columnindex 11
#define binf _p[12]
#define binf_columnindex 12
#define a _p[13]
#define a_columnindex 13
#define b _p[14]
#define b_columnindex 14
#define c _p[15]
#define c_columnindex 15
#define d _p[16]
#define d_columnindex 16
#define e _p[17]
#define e_columnindex 17
#define eca _p[18]
#define eca_columnindex 18
#define ica _p[19]
#define ica_columnindex 19
#define Da _p[20]
#define Da_columnindex 20
#define Db _p[21]
#define Db_columnindex 21
#define Dc _p[22]
#define Dc_columnindex 22
#define Dd _p[23]
#define Dd_columnindex 23
#define De _p[24]
#define De_columnindex 24
#define v _p[25]
#define v_columnindex 25
#define _g _p[26]
#define _g_columnindex 26
#define _ion_eca	*_ppvar[0]._pval
#define _ion_ica	*_ppvar[1]._pval
#define _ion_dicadv	*_ppvar[2]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static void _hoc_alphab(void);
 static void _hoc_alphaa(void);
 static void _hoc_alphae(void);
 static void _hoc_alphad(void);
 static void _hoc_alphac(void);
 static void _hoc_betab(void);
 static void _hoc_betaa(void);
 static void _hoc_betae(void);
 static void _hoc_betad(void);
 static void _hoc_betac(void);
 static void _hoc_exponential(void);
 static void _hoc_f(void);
 static void _hoc_logistic(void);
 static void _hoc_rates(void);
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static const char* nmodl_file_text;
static const char* nmodl_filename;
extern void hoc_reg_nmodl_text(int, const char*);
extern void hoc_reg_nmodl_filename(int, const char*);
#endif

 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _extcall_prop = _prop;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_Ca", _hoc_setdata,
 "alphab_Ca", _hoc_alphab,
 "alphaa_Ca", _hoc_alphaa,
 "alphae_Ca", _hoc_alphae,
 "alphad_Ca", _hoc_alphad,
 "alphac_Ca", _hoc_alphac,
 "betab_Ca", _hoc_betab,
 "betaa_Ca", _hoc_betaa,
 "betae_Ca", _hoc_betae,
 "betad_Ca", _hoc_betad,
 "betac_Ca", _hoc_betac,
 "exponential_Ca", _hoc_exponential,
 "f_Ca", _hoc_f,
 "logistic_Ca", _hoc_logistic,
 "rates_Ca", _hoc_rates,
 0, 0
};
#define alphab alphab_Ca
#define alphaa alphaa_Ca
#define alphae alphae_Ca
#define alphad alphad_Ca
#define alphac alphac_Ca
#define betab betab_Ca
#define betaa betaa_Ca
#define betae betae_Ca
#define betad betad_Ca
#define betac betac_Ca
#define exponential exponential_Ca
#define f f_Ca
#define logistic logistic_Ca
#define rates rates_Ca
 extern double alphab( _threadargsprotocomma_ double );
 extern double alphaa( _threadargsprotocomma_ double );
 extern double alphae( _threadargsprotocomma_ double );
 extern double alphad( _threadargsprotocomma_ double );
 extern double alphac( _threadargsprotocomma_ double );
 extern double betab( _threadargsprotocomma_ double );
 extern double betaa( _threadargsprotocomma_ double );
 extern double betae( _threadargsprotocomma_ double );
 extern double betad( _threadargsprotocomma_ double );
 extern double betac( _threadargsprotocomma_ double );
 extern double exponential( _threadargsprotocomma_ double , double , double , double );
 extern double f( _threadargsprotocomma_ double , double , double , double );
 extern double logistic( _threadargsprotocomma_ double , double , double , double );
 extern double rates( _threadargsprotocomma_ double );
 /* declare global and static user variables */
#define Vshift Vshift_Ca
 double Vshift = 0;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "Vshift_Ca", "mV",
 "gtcabar_Ca", "S/cm2",
 "gncabar_Ca", "S/cm2",
 "glcabar_Ca", "S/cm2",
 "i_Ca", "mA/cm2",
 "gtca_Ca", "S/cm2",
 "gnca_Ca", "S/cm2",
 "glca_Ca", "S/cm2",
 "gbar_Ca", "S/cm2",
 "taua_Ca", "ms",
 "taub_Ca", "ms",
 0,0
};
 static double a0 = 0;
 static double b0 = 0;
 static double c0 = 0;
 static double delta_t = 0.01;
 static double d0 = 0;
 static double e0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "Vshift_Ca", &Vshift_Ca,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(NrnThread*, _Memb_list*, int);
static void nrn_state(NrnThread*, _Memb_list*, int);
 static void nrn_cur(NrnThread*, _Memb_list*, int);
static void  nrn_jacob(NrnThread*, _Memb_list*, int);
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(NrnThread*, _Memb_list*, int);
static void _ode_matsol(NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[3]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"Ca",
 "gtcabar_Ca",
 "gncabar_Ca",
 "glcabar_Ca",
 "gcamult_Ca",
 0,
 "i_Ca",
 "gtca_Ca",
 "gnca_Ca",
 "glca_Ca",
 "gbar_Ca",
 "taua_Ca",
 "ainf_Ca",
 "taub_Ca",
 "binf_Ca",
 0,
 "a_Ca",
 "b_Ca",
 "c_Ca",
 "d_Ca",
 "e_Ca",
 0,
 0};
 static Symbol* _ca_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 27, _prop);
 	/*initialize range parameters*/
 	gtcabar = 0.00015;
 	gncabar = 0.002;
 	glcabar = 0.01;
 	gcamult = 1;
 	_prop->param = _p;
 	_prop->param_size = 27;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_ca_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* eca */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ica */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dicadv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _Aradi_Ca2_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("ca", -10000.);
 	_ca_sym = hoc_lookup("ca_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 27, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 Ca /Users/sandek/CA1Sim/Aradi_Ca2.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[5], _dlist1[5];
 static int state(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) {int _reset = 0; {
   rates ( _threadargscomma_ v ) ;
   Da = ( ainf - a ) / taua ;
   Db = ( binf - b ) / taub ;
   Dc = alphac ( _threadargscomma_ v ) * ( 1.0 - c ) - betac ( _threadargscomma_ v ) * c ;
   Dd = alphad ( _threadargscomma_ v ) * ( 1.0 - d ) - betad ( _threadargscomma_ v ) * d ;
   De = alphae ( _threadargscomma_ v ) * ( 1.0 - e ) - betae ( _threadargscomma_ v ) * e ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) {
 rates ( _threadargscomma_ v ) ;
 Da = Da  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taua )) ;
 Db = Db  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taub )) ;
 Dc = Dc  / (1. - dt*( ( alphac ( _threadargscomma_ v ) )*( ( ( - 1.0 ) ) ) - ( betac ( _threadargscomma_ v ) )*( 1.0 ) )) ;
 Dd = Dd  / (1. - dt*( ( alphad ( _threadargscomma_ v ) )*( ( ( - 1.0 ) ) ) - ( betad ( _threadargscomma_ v ) )*( 1.0 ) )) ;
 De = De  / (1. - dt*( ( alphae ( _threadargscomma_ v ) )*( ( ( - 1.0 ) ) ) - ( betae ( _threadargscomma_ v ) )*( 1.0 ) )) ;
  return 0;
}
 /*END CVODE*/
 static int state (double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) { {
   rates ( _threadargscomma_ v ) ;
    a = a + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / taua)))*(- ( ( ( ainf ) ) / taua ) / ( ( ( ( - 1.0 ) ) ) / taua ) - a) ;
    b = b + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / taub)))*(- ( ( ( binf ) ) / taub ) / ( ( ( ( - 1.0 ) ) ) / taub ) - b) ;
    c = c + (1. - exp(dt*(( alphac ( _threadargscomma_ v ) )*( ( ( - 1.0 ) ) ) - ( betac ( _threadargscomma_ v ) )*( 1.0 ))))*(- ( ( alphac ( _threadargscomma_ v ) )*( ( 1.0 ) ) ) / ( ( alphac ( _threadargscomma_ v ) )*( ( ( - 1.0 ) ) ) - ( betac ( _threadargscomma_ v ) )*( 1.0 ) ) - c) ;
    d = d + (1. - exp(dt*(( alphad ( _threadargscomma_ v ) )*( ( ( - 1.0 ) ) ) - ( betad ( _threadargscomma_ v ) )*( 1.0 ))))*(- ( ( alphad ( _threadargscomma_ v ) )*( ( 1.0 ) ) ) / ( ( alphad ( _threadargscomma_ v ) )*( ( ( - 1.0 ) ) ) - ( betad ( _threadargscomma_ v ) )*( 1.0 ) ) - d) ;
    e = e + (1. - exp(dt*(( alphae ( _threadargscomma_ v ) )*( ( ( - 1.0 ) ) ) - ( betae ( _threadargscomma_ v ) )*( 1.0 ))))*(- ( ( alphae ( _threadargscomma_ v ) )*( ( 1.0 ) ) ) / ( ( alphae ( _threadargscomma_ v ) )*( ( ( - 1.0 ) ) ) - ( betae ( _threadargscomma_ v ) )*( 1.0 ) ) - e) ;
   }
  return 0;
}
 
double rates ( _threadargsprotocomma_ double _lv ) {
   double _lrates;
 ainf = alphaa ( _threadargscomma_ _lv ) / ( alphaa ( _threadargscomma_ _lv ) + betaa ( _threadargscomma_ _lv ) ) ;
   taua = 1.0 / ( alphaa ( _threadargscomma_ _lv ) + betaa ( _threadargscomma_ _lv ) ) ;
   binf = alphab ( _threadargscomma_ _lv ) / ( alphab ( _threadargscomma_ _lv ) + betab ( _threadargscomma_ _lv ) ) ;
   taub = 1.0 / ( alphab ( _threadargscomma_ _lv + Vshift ) + betab ( _threadargscomma_ _lv + Vshift ) ) ;
   
return _lrates;
 }
 
static void _hoc_rates(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  rates ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double alphaa ( _threadargsprotocomma_ double _lv ) {
   double _lalphaa;
 _lalphaa = f ( _threadargscomma_ 2.0 , 0.1 , _lv , 19.26 ) ;
   
return _lalphaa;
 }
 
static void _hoc_alphaa(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  alphaa ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double betaa ( _threadargsprotocomma_ double _lv ) {
   double _lbetaa;
 _lbetaa = exponential ( _threadargscomma_ 0.009 , - 0.045393 , _lv , 0.0 ) ;
   
return _lbetaa;
 }
 
static void _hoc_betaa(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  betaa ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double alphab ( _threadargsprotocomma_ double _lv ) {
   double _lalphab;
 _lalphab = exponential ( _threadargscomma_ 1e-6 , - 0.061501 , _lv , 0.0 ) ;
   
return _lalphab;
 }
 
static void _hoc_alphab(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  alphab ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double betab ( _threadargsprotocomma_ double _lv ) {
   double _lbetab;
 _lbetab = logistic ( _threadargscomma_ 1.0 , - 0.1 , _lv , 29.79 ) ;
   
return _lbetab;
 }
 
static void _hoc_betab(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  betab ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double alphac ( _threadargsprotocomma_ double _lv ) {
   double _lalphac;
 _lalphac = f ( _threadargscomma_ 1.9 , 0.1 , _lv , 19.88 ) ;
   
return _lalphac;
 }
 
static void _hoc_alphac(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  alphac ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double betac ( _threadargsprotocomma_ double _lv ) {
   double _lbetac;
 _lbetac = exponential ( _threadargscomma_ 0.046 , - 0.048239 , _lv , 0.0 ) ;
   
return _lbetac;
 }
 
static void _hoc_betac(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  betac ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double alphad ( _threadargsprotocomma_ double _lv ) {
   double _lalphad;
 _lalphad = exponential ( _threadargscomma_ 1.6e-4 , - 0.020661 , _lv , 0.0 ) ;
   
return _lalphad;
 }
 
static void _hoc_alphad(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  alphad ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double betad ( _threadargsprotocomma_ double _lv ) {
   double _lbetad;
 _lbetad = logistic ( _threadargscomma_ 1.0 , - 0.1 , _lv , 39.0 ) ;
   
return _lbetad;
 }
 
static void _hoc_betad(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  betad ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double alphae ( _threadargsprotocomma_ double _lv ) {
   double _lalphae;
 _lalphae = f ( _threadargscomma_ 156.9 , 0.1 , _lv , 81.5 ) ;
   
return _lalphae;
 }
 
static void _hoc_alphae(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  alphae ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double betae ( _threadargsprotocomma_ double _lv ) {
   double _lbetae;
 _lbetae = exponential ( _threadargscomma_ 0.29 , - 0.092081 , _lv , 0.0 ) ;
   
return _lbetae;
 }
 
static void _hoc_betae(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  betae ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double f ( _threadargsprotocomma_ double _lA , double _lk , double _lv , double _lD ) {
   double _lf;
 double _lx ;
 _lx = _lk * ( _lv - _lD ) ;
   if ( fabs ( _lx ) > 1e-6 ) {
     _lf = _lA * _lx / ( 1.0 - exp ( - _lx ) ) ;
     }
   else {
     _lf = _lA / ( 1.0 - 0.5 * _lx ) ;
     }
   
return _lf;
 }
 
static void _hoc_f(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  f ( _p, _ppvar, _thread, _nt, *getarg(1) , *getarg(2) , *getarg(3) , *getarg(4) );
 hoc_retpushx(_r);
}
 
double logistic ( _threadargsprotocomma_ double _lA , double _lk , double _lv , double _lD ) {
   double _llogistic;
 _llogistic = _lA / ( 1.0 + exp ( _lk * ( _lv - _lD ) ) ) ;
   
return _llogistic;
 }
 
static void _hoc_logistic(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  logistic ( _p, _ppvar, _thread, _nt, *getarg(1) , *getarg(2) , *getarg(3) , *getarg(4) );
 hoc_retpushx(_r);
}
 
double exponential ( _threadargsprotocomma_ double _lA , double _lk , double _lv , double _lD ) {
   double _lexponential;
 _lexponential = _lA * exp ( _lk * ( _lv - _lD ) ) ;
   
return _lexponential;
 }
 
static void _hoc_exponential(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  exponential ( _p, _ppvar, _thread, _nt, *getarg(1) , *getarg(2) , *getarg(3) , *getarg(4) );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ return 5;}
 
static void _ode_spec(NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  eca = _ion_eca;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 5; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _ode_matsol1 (_p, _ppvar, _thread, _nt);
 }
 
static void _ode_matsol(NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  eca = _ion_eca;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_ca_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 2, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) {
  int _i; double _save;{
  a = a0;
  b = b0;
  c = c0;
  d = d0;
  e = e0;
 {
   rates ( _threadargscomma_ v ) ;
   a = ainf ;
   b = binf ;
   c = alphac ( _threadargscomma_ v ) / ( alphac ( _threadargscomma_ v ) + betac ( _threadargscomma_ v ) ) ;
   d = alphad ( _threadargscomma_ v ) / ( alphad ( _threadargscomma_ v ) + betad ( _threadargscomma_ v ) ) ;
   e = alphae ( _threadargscomma_ v ) / ( alphae ( _threadargscomma_ v ) + betae ( _threadargscomma_ v ) ) ;
   gbar = gcamult * ( gtcabar + gncabar + glcabar ) ;
   gtca = gtcabar * gcamult * a * a * b ;
   gnca = gncabar * gcamult * c * c * d ;
   glca = glcabar * gcamult * e * e ;
   ica = ( gtca + gnca + glca ) * ( v - eca ) ;
   i = ica ;
   }
 
}
}

static void nrn_init(NrnThread* _nt, _Memb_list* _ml, int _type){
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
  eca = _ion_eca;
 initmodel(_p, _ppvar, _thread, _nt);
 }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   gtca = gtcabar * gcamult * a * a * b ;
   gnca = gncabar * gcamult * c * c * d ;
   glca = glcabar * gcamult * e * e ;
   ica = ( gtca + gnca + glca ) * ( v - eca ) ;
   i = ica ;
   }
 _current += ica;

} return _current;
}

static void nrn_cur(NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
  eca = _ion_eca;
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _dica;
  _dica = ica;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dicadv += (_dica - ica)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ica += ica ;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}
 
}

static void nrn_jacob(NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}
 
}

static void nrn_state(NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
  eca = _ion_eca;
 {   state(_p, _ppvar, _thread, _nt);
  } }}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = a_columnindex;  _dlist1[0] = Da_columnindex;
 _slist1[1] = b_columnindex;  _dlist1[1] = Db_columnindex;
 _slist1[2] = c_columnindex;  _dlist1[2] = Dc_columnindex;
 _slist1[3] = d_columnindex;  _dlist1[3] = Dd_columnindex;
 _slist1[4] = e_columnindex;  _dlist1[4] = De_columnindex;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/Users/sandek/CA1Sim/Aradi_Ca2.mod";
static const char* nmodl_file_text = 
  ": Ca channels (T,N,L-type)\n"
  "\n"
  "\n"
  "NEURON {\n"
  "	SUFFIX Ca\n"
  "	USEION ca READ eca WRITE ica\n"
  "	RANGE gtcabar, gncabar, glcabar, gtca, gnca, glca\n"
  "	RANGE ainf, taua, binf, taub, gbar, gcamult, i\n"
  "	GLOBAL Vshift\n"
  "}\n"
  "\n"
  "UNITS {\n"
  "	(molar) = (1/liter)\n"
  "	(mM) = (millimolar)\n"
  "	(mV) = (millivolt)\n"
  "	(mA) = (milliamp)\n"
  "	(S) = (siemens)\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "	gtcabar = .00015	(S/cm2)\n"
  "	gncabar = .002	(S/cm2)\n"
  "	glcabar = .01	(S/cm2)\n"
  "    gcamult = 1.\n"
  "	Vshift = 0    (mV)\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "	v		(mV)\n"
  "    eca     (mV)\n"
  "	ica	(mA/cm2)\n"
  "	i	(mA/cm2)\n"
  "	gtca		(S/cm2)\n"
  "	gnca		(S/cm2)\n"
  "	glca		(S/cm2)\n"
  "	gbar		(S/cm2)\n"
  "	celsius	(degC)\n"
  "	taua    (ms)\n"
  "	ainf\n"
  "	taub    (ms)\n"
  "	binf\n"
  "}\n"
  "\n"
  "STATE {\n"
  "	a \n"
  "	b \n"
  "	c \n"
  "	d \n"
  "	e\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "    SOLVE state METHOD cnexp\n"
  "	gtca = gtcabar*gcamult*a*a*b\n"
  "	gnca = gncabar*gcamult*c*c*d\n"
  "	glca = glcabar*gcamult*e*e\n"
  "	ica = (gtca+gnca+glca)*(v - eca)\n"
  "	i = ica\n"
  "}\n"
  "\n"
  "DERIVATIVE state {\n"
  "	rates(v)\n"
  "	a' = (ainf - a)/taua\n"
  "	b' = (binf - b)/taub\n"
  "	c' = alphac(v)*(1-c)-betac(v)*c\n"
  "	d' = alphad(v)*(1-d)-betad(v)*d\n"
  "	e' = alphae(v)*(1-e)-betae(v)*e\n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "	rates(v)\n"
  "	a = ainf\n"
  "	b = binf\n"
  "	c = alphac(v)/(alphac(v)+betac(v))\n"
  "	d = alphad(v)/(alphad(v)+betad(v))\n"
  "	e = alphae(v)/(alphae(v)+betae(v))\n"
  "	gbar = gcamult * (gtcabar + gncabar + glcabar)\n"
  "	gtca = gtcabar*gcamult*a*a*b\n"
  "	gnca = gncabar*gcamult*c*c*d\n"
  "	glca = glcabar*gcamult*e*e\n"
  "	ica = (gtca+gnca+glca)*(v - eca)\n"
  "	i = ica\n"
  "}\n"
  "\n"
  "FUNCTION rates(v (mV)) {\n"
  "	ainf = alphaa(v)/(alphaa(v) + betaa(v))\n"
  "	taua = 1/(alphaa(v) + betaa(v))\n"
  "	binf = alphab(v)/(alphab(v) + betab(v))\n"
  "	taub = 1/(alphab(v+Vshift) + betab(v+Vshift))\n"
  "}\n"
  "\n"
  "FUNCTION alphaa(v (mV)) (/ms) {\n"
  "	alphaa = f(2,0.1,v,19.26)\n"
  "}\n"
  "\n"
  "FUNCTION betaa(v (mV)) (/ms) {\n"
  "	betaa = exponential(0.009,-0.045393,v,0)\n"
  "}\n"
  "\n"
  "FUNCTION alphab(v (mV)) (/ms) {\n"
  "	alphab = exponential(1e-6,-0.061501,v,0)\n"
  "}\n"
  "\n"
  "FUNCTION betab(v (mV)) (/ms) {\n"
  "	betab = logistic(1,-0.1,v,29.79)\n"
  "}\n"
  "\n"
  "FUNCTION alphac(v (mV)) (/ms) {\n"
  "	alphac = f(1.9,0.1,v,19.88)\n"
  "}\n"
  "\n"
  "FUNCTION betac(v (mV)) (/ms) {\n"
  "	betac = exponential(0.046,-0.048239,v,0)\n"
  "}\n"
  "\n"
  "FUNCTION alphad(v (mV)) (/ms) {\n"
  "	alphad = exponential(1.6e-4,-0.020661,v,0)\n"
  "}\n"
  "\n"
  "FUNCTION betad(v (mV)) (/ms) {\n"
  "	betad = logistic(1,-0.1,v,39)\n"
  "}\n"
  "\n"
  "FUNCTION alphae(v (mV)) (/ms) {\n"
  "	alphae = f(156.9,0.1,v,81.5)\n"
  "}\n"
  "\n"
  "FUNCTION betae(v (mV)) (/ms) {\n"
  "	betae = exponential(0.29,-0.092081,v,0)\n"
  "}\n"
  "\n"
  "FUNCTION f(A, k, v (mV), D) (/ms) {\n"
  "	LOCAL x\n"
  "	x = k*(v-D)\n"
  "	if (fabs(x) > 1e-6) {\n"
  "		f = A*x/(1-exp(-x))\n"
  "	}else{\n"
  "		f = A/(1-0.5*x)\n"
  "	}\n"
  "}\n"
  "\n"
  "FUNCTION logistic(A, k, v (mV), D) (/ms) {\n"
  "	logistic = A/(1+exp(k*(v-D)))\n"
  "}\n"
  "\n"
  "FUNCTION exponential(A, k, v (mV), D) (/ms) {\n"
  "	exponential = A*exp(k*(v-D))\n"
  "}\n"
  ;
#endif
