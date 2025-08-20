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
 
#define nrn_init _nrn_init__CadepK_orig
#define _nrn_initial _nrn_initial__CadepK_orig
#define nrn_cur _nrn_cur__CadepK_orig
#define _nrn_current _nrn_current__CadepK_orig
#define nrn_jacob _nrn_jacob__CadepK_orig
#define nrn_state _nrn_state__CadepK_orig
#define _net_receive _net_receive__CadepK_orig 
#define state state__CadepK_orig 
 
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
#define gbkbar _p[0]
#define gbkbar_columnindex 0
#define gskbar _p[1]
#define gskbar_columnindex 1
#define gcakmult _p[2]
#define gcakmult_columnindex 2
#define ask _p[3]
#define ask_columnindex 3
#define bsk _p[4]
#define bsk_columnindex 4
#define isk _p[5]
#define isk_columnindex 5
#define ibk _p[6]
#define ibk_columnindex 6
#define i _p[7]
#define i_columnindex 7
#define gbk _p[8]
#define gbk_columnindex 8
#define gsk _p[9]
#define gsk_columnindex 9
#define gbar _p[10]
#define gbar_columnindex 10
#define ca_i _p[11]
#define ca_i_columnindex 11
#define q _p[12]
#define q_columnindex 12
#define r _p[13]
#define r_columnindex 13
#define s _p[14]
#define s_columnindex 14
#define ek _p[15]
#define ek_columnindex 15
#define ik _p[16]
#define ik_columnindex 16
#define ica _p[17]
#define ica_columnindex 17
#define Dca_i _p[18]
#define Dca_i_columnindex 18
#define Dq _p[19]
#define Dq_columnindex 19
#define Dr _p[20]
#define Dr_columnindex 20
#define Ds _p[21]
#define Ds_columnindex 21
#define v _p[22]
#define v_columnindex 22
#define _g _p[23]
#define _g_columnindex 23
#define _ion_ica	*_ppvar[0]._pval
#define _ion_ek	*_ppvar[1]._pval
#define _ion_ik	*_ppvar[2]._pval
#define _ion_dikdv	*_ppvar[3]._pval
#define area	*_ppvar[4]._pval
 
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
 /* declaration of user functions */
 static void _hoc_alphaq(void);
 static void _hoc_betar(void);
 static void _hoc_betaq(void);
 static void _hoc_exptrap(void);
 static void _hoc_exp1(void);
 static void _hoc_sinf(void);
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
 "setdata_CadepK_orig", _hoc_setdata,
 "alphaq_CadepK_orig", _hoc_alphaq,
 "betar_CadepK_orig", _hoc_betar,
 "betaq_CadepK_orig", _hoc_betaq,
 "exptrap_CadepK_orig", _hoc_exptrap,
 "exp1_CadepK_orig", _hoc_exp1,
 "sinf_CadepK_orig", _hoc_sinf,
 0, 0
};
#define alphaq alphaq_CadepK_orig
#define betar betar_CadepK_orig
#define betaq betaq_CadepK_orig
#define exptrap exptrap_CadepK_orig
#define exp1 exp1_CadepK_orig
#define sinf sinf_CadepK_orig
 extern double alphaq( _threadargsprotocomma_ double );
 extern double betar( _threadargsprotocomma_ double );
 extern double betaq( _threadargsprotocomma_ double );
 extern double exptrap( _threadargsprotocomma_ double );
 extern double exp1( _threadargsprotocomma_ double , double , double , double );
 extern double sinf( _threadargsprotocomma_ double );
 /* declare global and static user variables */
#define alphar alphar_CadepK_orig
 double alphar = 7.5;
#define ca0 ca0_CadepK_orig
 double ca0 = 7e-05;
#define stau stau_CadepK_orig
 double stau = 10;
#define tauskdiv tauskdiv_CadepK_orig
 double tauskdiv = 1;
#define taucadiv taucadiv_CadepK_orig
 double taucadiv = 1;
#define tau tau_CadepK_orig
 double tau = 9;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "ca0_CadepK_orig", "mM",
 "tau_CadepK_orig", "ms",
 "alphar_CadepK_orig", "/ms",
 "stau_CadepK_orig", "ms",
 "gbkbar_CadepK_orig", "S/cm2",
 "gskbar_CadepK_orig", "S/cm2",
 "ca_i_CadepK_orig", "mM",
 "isk_CadepK_orig", "mA/cm2",
 "ibk_CadepK_orig", "mA/cm2",
 "i_CadepK_orig", "mA/cm2",
 "gbk_CadepK_orig", "S/cm2",
 "gsk_CadepK_orig", "S/cm2",
 "gbar_CadepK_orig", "S/cm2",
 0,0
};
 static double ca_i0 = 0;
 static double delta_t = 0.01;
 static double q0 = 0;
 static double r0 = 0;
 static double s0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "ca0_CadepK_orig", &ca0_CadepK_orig,
 "tau_CadepK_orig", &tau_CadepK_orig,
 "taucadiv_CadepK_orig", &taucadiv_CadepK_orig,
 "tauskdiv_CadepK_orig", &tauskdiv_CadepK_orig,
 "alphar_CadepK_orig", &alphar_CadepK_orig,
 "stau_CadepK_orig", &stau_CadepK_orig,
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
 
#define _cvode_ieq _ppvar[5]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"CadepK_orig",
 "gbkbar_CadepK_orig",
 "gskbar_CadepK_orig",
 "gcakmult_CadepK_orig",
 "ask_CadepK_orig",
 "bsk_CadepK_orig",
 0,
 "isk_CadepK_orig",
 "ibk_CadepK_orig",
 "i_CadepK_orig",
 "gbk_CadepK_orig",
 "gsk_CadepK_orig",
 "gbar_CadepK_orig",
 0,
 "ca_i_CadepK_orig",
 "q_CadepK_orig",
 "r_CadepK_orig",
 "s_CadepK_orig",
 0,
 0};
 extern Node* nrn_alloc_node_;
 static Symbol* _ca_sym;
 static Symbol* _k_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 24, _prop);
 	/*initialize range parameters*/
 	gbkbar = 0.0003;
 	gskbar = 0.0005;
 	gcakmult = 1;
 	ask = 1;
 	bsk = 1;
 	_prop->param = _p;
 	_prop->param_size = 24;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 6, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 	_ppvar[4]._pval = &nrn_alloc_node_->_area; /* diam */
 prop_ion = need_memb(_ca_sym);
 	_ppvar[0]._pval = &prop_ion->param[3]; /* ica */
 prop_ion = need_memb(_k_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[1]._pval = &prop_ion->param[0]; /* ek */
 	_ppvar[2]._pval = &prop_ion->param[3]; /* ik */
 	_ppvar[3]._pval = &prop_ion->param[4]; /* _ion_dikdv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 "ca_i_CadepK_orig", 1e-05,
 0,0
};
 static void _thread_mem_init(Datum*);
 static void _thread_cleanup(Datum*);
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _Aradi_CadepK_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("ca", -10000.);
 	ion_reg("k", -10000.);
 	_ca_sym = hoc_lookup("ca_ion");
 	_k_sym = hoc_lookup("k_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 5);
  _extcall_thread = (Datum*)ecalloc(4, sizeof(Datum));
  _thread_mem_init(_extcall_thread);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 1, _thread_mem_init);
     _nrn_thread_reg(_mechtype, 0, _thread_cleanup);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 24, 6);
  hoc_register_dparam_semantics(_mechtype, 0, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 5, "cvodeieq");
  hoc_register_dparam_semantics(_mechtype, 4, "area");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 CadepK_orig /Users/sandek/CA1Sim/Aradi_CadepK.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double B = .26;
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
 
#define _deriv1_advance _thread[0]._i
#define _dith1 1
#define _recurse _thread[2]._i
#define _newtonspace1 _thread[3]._pvoid
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist2[4];
  static int _slist1[4], _dlist1[4];
 static int state(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) {int _reset = 0; {
   Dca_i = - B * ica - taucadiv * ( ca_i - ca0 ) / tau ;
   Dq = tauskdiv * ( ask * alphaq ( _threadargscomma_ ca_i ) * ( 1.0 - q ) - bsk * betaq ( _threadargscomma_ ca_i ) * q ) ;
   Dr = alphar * ( 1.0 - r ) - betar ( _threadargscomma_ v ) * r ;
   Ds = ( sinf ( _threadargscomma_ ca_i ) - s ) / stau ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) {
 Dca_i = Dca_i  / (1. - dt*( ( - ( ( taucadiv )*( ( 1.0 ) ) ) / tau ) )) ;
 Dq = Dq  / (1. - dt*( ( tauskdiv )*( ( ( ask * alphaq ( _threadargscomma_ ca_i ) )*( ( ( - 1.0 ) ) ) - ( bsk * betaq ( _threadargscomma_ ca_i ) )*( 1.0 ) ) ) )) ;
 Dr = Dr  / (1. - dt*( ( alphar )*( ( ( - 1.0 ) ) ) - ( betar ( _threadargscomma_ v ) )*( 1.0 ) )) ;
 Ds = Ds  / (1. - dt*( ( ( ( - 1.0 ) ) ) / stau )) ;
  return 0;
}
 /*END CVODE*/
 
static int state (double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) {int _reset=0; int error = 0;
 { double* _savstate1 = _thread[_dith1]._pval;
 double* _dlist2 = _thread[_dith1]._pval + 4;
 int _counte = -1;
 if (!_recurse) {
 _recurse = 1;
 {int _id; for(_id=0; _id < 4; _id++) { _savstate1[_id] = _p[_slist1[_id]];}}
 error = nrn_newton_thread(_newtonspace1, 4,_slist2, _p, state, _dlist2, _ppvar, _thread, _nt);
 _recurse = 0; if(error) {abort_run(error);}}
 {
   Dca_i = - B * ica - taucadiv * ( ca_i - ca0 ) / tau ;
   Dq = tauskdiv * ( ask * alphaq ( _threadargscomma_ ca_i ) * ( 1.0 - q ) - bsk * betaq ( _threadargscomma_ ca_i ) * q ) ;
   Dr = alphar * ( 1.0 - r ) - betar ( _threadargscomma_ v ) * r ;
   Ds = ( sinf ( _threadargscomma_ ca_i ) - s ) / stau ;
   {int _id; for(_id=0; _id < 4; _id++) {
if (_deriv1_advance) {
 _dlist2[++_counte] = _p[_dlist1[_id]] - (_p[_slist1[_id]] - _savstate1[_id])/dt;
 }else{
_dlist2[++_counte] = _p[_slist1[_id]] - _savstate1[_id];}}}
 } }
 return _reset;}
 
double exp1 ( _threadargsprotocomma_ double _lA , double _ld , double _lk , double _lx ) {
   double _lexp1;
  _lexp1 = _lA / exptrap ( _threadargscomma_ ( 12.0 * log10 ( _lx ) + _ld ) / _lk ) ;
    
return _lexp1;
 }
 
static void _hoc_exp1(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  exp1 ( _p, _ppvar, _thread, _nt, *getarg(1) , *getarg(2) , *getarg(3) , *getarg(4) );
 hoc_retpushx(_r);
}
 
double alphaq ( _threadargsprotocomma_ double _lx ) {
   double _lalphaq;
 _lalphaq = exp1 ( _threadargscomma_ 0.00246 , 28.48 , - 4.5 , _lx ) ;
   
return _lalphaq;
 }
 
static void _hoc_alphaq(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  alphaq ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double betaq ( _threadargsprotocomma_ double _lx ) {
   double _lbetaq;
 _lbetaq = exp1 ( _threadargscomma_ 0.006 , 60.4 , 35.0 , _lx ) ;
   
return _lbetaq;
 }
 
static void _hoc_betaq(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  betaq ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double betar ( _threadargsprotocomma_ double _lv ) {
   double _lbetar;
  _lbetar = 0.11 / exptrap ( _threadargscomma_ ( _lv - 35.0 ) / 14.9 ) ;
    
return _lbetar;
 }
 
static void _hoc_betar(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  betar ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double sinf ( _threadargsprotocomma_ double _lx ) {
   double _lsinf;
  _lsinf = 1.0 / ( 1.0 + 4.0 / ( 1000.0 * _lx ) ) ;
    
return _lsinf;
 }
 
static void _hoc_sinf(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  sinf ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double exptrap ( _threadargsprotocomma_ double _lx ) {
   double _lexptrap;
 if ( _lx >= 700.0 ) {
     _lexptrap = exp ( 700.0 ) ;
     }
   else {
     _lexptrap = exp ( _lx ) ;
     }
   
return _lexptrap;
 }
 
static void _hoc_exptrap(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  exptrap ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ return 4;}
 
static void _ode_spec(NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ica = _ion_ica;
  ek = _ion_ek;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 4; ++_i) {
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
  ica = _ion_ica;
  ek = _ion_ek;
 _ode_matsol_instance1(_threadargs_);
 }}
 
static void _thread_mem_init(Datum* _thread) {
   _thread[_dith1]._pval = (double*)ecalloc(8, sizeof(double));
   _newtonspace1 = nrn_cons_newtonspace(4);
 }
 
static void _thread_cleanup(Datum* _thread) {
   free((void*)(_thread[_dith1]._pval));
   nrn_destroy_newtonspace(_newtonspace1);
 }
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_ca_sym, _ppvar, 0, 3);
   nrn_update_ion_pointer(_k_sym, _ppvar, 1, 0);
   nrn_update_ion_pointer(_k_sym, _ppvar, 2, 3);
   nrn_update_ion_pointer(_k_sym, _ppvar, 3, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) {
  int _i; double _save;{
  ca_i = ca_i0;
  q = q0;
  r = r0;
  s = s0;
 {
   ca_i = ca0 ;
   q = alphaq ( _threadargscomma_ ca_i ) / ( alphaq ( _threadargscomma_ ca_i ) + betaq ( _threadargscomma_ ca_i ) ) ;
   r = alphar / ( alphar + betar ( _threadargscomma_ v ) ) ;
   s = sinf ( _threadargscomma_ ca_i ) ;
   gbar = gbkbar + gskbar ;
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
  ica = _ion_ica;
  ek = _ion_ek;
 initmodel(_p, _ppvar, _thread, _nt);
 }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   gbk = gbkbar * gcakmult * r * s * s ;
   gsk = gskbar * gcakmult * q * q ;
   isk = gsk * ( v - ek ) ;
   ibk = gbk * ( v - ek ) ;
   ik = isk + ibk ;
   i = ik ;
   }
 _current += ik;

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
  ica = _ion_ica;
  ek = _ion_ek;
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _dik;
  _dik = ik;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dikdv += (_dik - ik)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ik += ik ;
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
double _dtsav = dt;
if (secondorder) { dt *= 0.5; }
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
  ica = _ion_ica;
  ek = _ion_ek;
 {  _deriv1_advance = 1;
 derivimplicit_thread(4, _slist1, _dlist1, _p, state, _ppvar, _thread, _nt);
_deriv1_advance = 0;
     if (secondorder) {
    int _i;
    for (_i = 0; _i < 4; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 } }}
 dt = _dtsav;
}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = ca_i_columnindex;  _dlist1[0] = Dca_i_columnindex;
 _slist1[1] = q_columnindex;  _dlist1[1] = Dq_columnindex;
 _slist1[2] = r_columnindex;  _dlist1[2] = Dr_columnindex;
 _slist1[3] = s_columnindex;  _dlist1[3] = Ds_columnindex;
 _slist2[0] = ca_i_columnindex;
 _slist2[1] = q_columnindex;
 _slist2[2] = r_columnindex;
 _slist2[3] = s_columnindex;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/Users/sandek/CA1Sim/Aradi_CadepK.mod";
static const char* nmodl_file_text = 
  ": Ca-dependent K channels (BK and SK)\n"
  "\n"
  "\n"
  "NEURON {\n"
  "	SUFFIX CadepK_orig\n"
  "	USEION ca READ ica\n"
  "	USEION k READ ek WRITE ik\n"
  "	RANGE gbkbar, gskbar, gbar, i, ask, bsk, gsk, gbk, isk, ibk, gcakmult, ca_i\n"
  "	GLOBAL ca0, tau, stau, taucadiv, tauskdiv\n"
  "}\n"
  "\n"
  "UNITS {\n"
  "	(molar) = (1/liter)\n"
  "	(mM) = (millimolar)\n"
  "	(mV) = (millivolt)\n"
  "	(mA) = (milliamp)\n"
  "	(S) = (siemens)\n"
  "	B = .26 (mM-cm2/mA-ms)\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "	gbkbar = .0003	(S/cm2)	: maximum permeability\n"
  "	gskbar = .0005	(S/cm2)	: maximum permeability\n"
  "	gcakmult = 1.\n"
  "	ca0 = .00007	(mM)\n"
  "	tau = 9		(ms)\n"
  "	taucadiv = 1\n"
  "	tauskdiv = 1\n"
  "	ask = 1\n"
  "	bsk = 1\n"
  "	alphar = 7.5	(/ms)\n"
  "	stau = 10		(ms)\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "	v			(mV)\n"
  "	ek		(mV)\n"
  "	ik		(mA/cm2)\n"
  "	isk		(mA/cm2)\n"
  "	ibk		(mA/cm2)\n"
  "	i 		(mA/cm2)\n"
  "	ica		(mA/cm2)\n"
  "	area	(microm2)\n"
  "  	gbk		(S/cm2)\n"
  "  	gsk		(S/cm2)\n"
  "  	gbar  (S/cm2)\n"
  "}\n"
  "\n"
  "STATE { \n"
  "	ca_i (mM)		<1e-5> \n"
  "	q \n"
  "	r \n"
  "	s \n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "	SOLVE state METHOD derivimplicit\n"
  "	gbk = gbkbar*gcakmult*r*s*s\n"
  "	gsk = gskbar*gcakmult*q*q\n"
  "	isk = gsk*(v - ek)\n"
  "	ibk = gbk*(v - ek)\n"
  "	ik = isk + ibk\n"
  "	i = ik\n"
  "}\n"
  "\n"
  "DERIVATIVE state {	: exact when v held constant; integrates over dt step\n"
  "	ca_i' = -B*ica - taucadiv*(ca_i-ca0)/tau\n"
  "	q' = tauskdiv*(ask*alphaq(ca_i)*(1-q)-bsk*betaq(ca_i)*q)\n"
  "	r' = alphar*(1-r)-betar(v)*r\n"
  "	s' = (sinf(ca_i)-s)/stau\n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "	ca_i = ca0\n"
  "	q = alphaq(ca_i)/(alphaq(ca_i)+betaq(ca_i))\n"
  "	r = alphar/(alphar+betar(v))\n"
  "  	s = sinf(ca_i)\n"
  "  	gbar = gbkbar + gskbar\n"
  "}\n"
  "\n"
  "FUNCTION exp1(A (/ms), d, k, x (mM)) (/ms) {\n"
  "	UNITSOFF\n"
  "	exp1 = A/exptrap((12*log10(x)+d)/k)\n"
  "	UNITSON\n"
  "}\n"
  "\n"
  "FUNCTION alphaq(x (mM)) (/ms) {\n"
  "	alphaq = exp1(0.00246,28.48,-4.5,x)	:28\n"
  "}\n"
  "\n"
  "FUNCTION betaq(x (mM)) (/ms) {\n"
  "	betaq = exp1(0.006,60.4,35,x)\n"
  "}\n"
  "\n"
  "FUNCTION betar(v (mV)) (/ms) {\n"
  "	UNITSOFF\n"
  "	betar = 0.11/exptrap((v-35)/14.9)\n"
  "	UNITSON\n"
  "}\n"
  "\n"
  "FUNCTION sinf(x (mM)) {\n"
  "	UNITSOFF\n"
  "	sinf = 1/(1+4/(1000*x))\n"
  "	UNITSON\n"
  "}\n"
  "\n"
  "FUNCTION exptrap(x) {\n"
  "  if (x>=700.0) {\n"
  "    exptrap = exp(700.0)\n"
  "  } else {\n"
  "    exptrap = exp(x)\n"
  "  }\n"
  "}\n"
  ;
#endif
