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
 
#define nrn_init _nrn_init__hh3nax
#define _nrn_initial _nrn_initial__hh3nax
#define nrn_cur _nrn_cur__hh3nax
#define _nrn_current _nrn_current__hh3nax
#define nrn_jacob _nrn_jacob__hh3nax
#define nrn_state _nrn_state__hh3nax
#define _net_receive _net_receive__hh3nax 
#define states states__hh3nax 
 
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
#define gbar _p[0]
#define gbar_columnindex 0
#define g _p[1]
#define g_columnindex 1
#define h _p[2]
#define h_columnindex 2
#define m _p[3]
#define m_columnindex 3
#define Dh _p[4]
#define Dh_columnindex 4
#define Dm _p[5]
#define Dm_columnindex 5
#define ina _p[6]
#define ina_columnindex 6
#define ena _p[7]
#define ena_columnindex 7
#define v _p[8]
#define v_columnindex 8
#define _g _p[9]
#define _g_columnindex 9
#define _ion_ena	*_ppvar[0]._pval
#define _ion_ina	*_ppvar[1]._pval
#define _ion_dinadv	*_ppvar[2]._pval
 
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
 static void _hoc_ssh(void);
 static void _hoc_ssm(void);
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
 "setdata_hh3nax", _hoc_setdata,
 "ssh_hh3nax", _hoc_ssh,
 "ssm_hh3nax", _hoc_ssm,
 0, 0
};
#define _f_ssh _f_ssh_hh3nax
#define _f_ssm _f_ssm_hh3nax
#define ssh ssh_hh3nax
#define ssm ssm_hh3nax
 extern double _f_ssh( _threadargsprotocomma_ double );
 extern double _f_ssm( _threadargsprotocomma_ double );
 extern double ssh( _threadargsprotocomma_ double );
 extern double ssm( _threadargsprotocomma_ double );
 
static void _check_ssm(double*, Datum*, Datum*, NrnThread*); 
static void _check_ssh(double*, Datum*, Datum*, NrnThread*); 
static void _check_table_thread(double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt, int _type) {
   _check_ssm(_p, _ppvar, _thread, _nt);
   _check_ssh(_p, _ppvar, _thread, _nt);
 }
 /* declare global and static user variables */
#define powh powh_hh3nax
 double powh = 1;
#define powm powm_hh3nax
 double powm = 3;
#define tauh tauh_hh3nax
 double tauh = 0.5;
#define taum taum_hh3nax
 double taum = 0.05;
#define usetable usetable_hh3nax
 double usetable = 1;
#define vmax vmax_hh3nax
 double vmax = 100;
#define vmin vmin_hh3nax
 double vmin = -120;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 "usetable_hh3nax", 0, 1,
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "vmin_hh3nax", "mV",
 "vmax_hh3nax", "mV",
 "taum_hh3nax", "ms",
 "tauh_hh3nax", "ms",
 "gbar_hh3nax", "mho/cm2",
 "g_hh3nax", "mho/cm2",
 0,0
};
 static double delta_t = 0.01;
 static double h0 = 0;
 static double m0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "vmin_hh3nax", &vmin_hh3nax,
 "vmax_hh3nax", &vmax_hh3nax,
 "taum_hh3nax", &taum_hh3nax,
 "tauh_hh3nax", &tauh_hh3nax,
 "powm_hh3nax", &powm_hh3nax,
 "powh_hh3nax", &powh_hh3nax,
 "usetable_hh3nax", &usetable_hh3nax,
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
"hh3nax",
 "gbar_hh3nax",
 0,
 "g_hh3nax",
 0,
 "h_hh3nax",
 "m_hh3nax",
 0,
 0};
 static Symbol* _na_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 10, _prop);
 	/*initialize range parameters*/
 	gbar = 0.2;
 	_prop->param = _p;
 	_prop->param_size = 10;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_na_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* ena */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ina */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dinadv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 "h_hh3nax", 0.1,
 "m_hh3nax", 0.1,
 0,0
};
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _hh3nax_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("na", -10000.);
 	_na_sym = hoc_lookup("na_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
     _nrn_thread_table_reg(_mechtype, _check_table_thread);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 10, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 hh3nax /Users/sandek/CA1Sim/hh3nax.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double *_t_ssm;
 static double *_t_ssh;
static int _reset;
static char *modelname = "HH na channel";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static double _n_ssh(_threadargsprotocomma_ double _lv);
 static double _n_ssm(_threadargsprotocomma_ double _lv);
 static int _slist1[2], _dlist1[2];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) {int _reset = 0; {
   Dm = ( ssm ( _threadargscomma_ v ) - m ) / taum ;
   Dh = ( ssh ( _threadargscomma_ v ) - h ) / tauh ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) {
 Dm = Dm  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taum )) ;
 Dh = Dh  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tauh )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) { {
    m = m + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / taum)))*(- ( ( ( ssm ( _threadargscomma_ v ) ) ) / taum ) / ( ( ( ( - 1.0 ) ) ) / taum ) - m) ;
    h = h + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tauh)))*(- ( ( ( ssh ( _threadargscomma_ v ) ) ) / tauh ) / ( ( ( ( - 1.0 ) ) ) / tauh ) - h) ;
   }
  return 0;
}
 static double _mfac_ssm, _tmin_ssm;
  static void _check_ssm(double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) {
  static int _maktable=1; int _i, _j, _ix = 0;
  double _xi, _tmax;
  if (!usetable) {return;}
  if (_maktable) { double _x, _dx; _maktable=0;
   _tmin_ssm =  vmin ;
   _tmax =  vmax ;
   _dx = (_tmax - _tmin_ssm)/200.; _mfac_ssm = 1./_dx;
   for (_i=0, _x=_tmin_ssm; _i < 201; _x += _dx, _i++) {
    _t_ssm[_i] = _f_ssm(_p, _ppvar, _thread, _nt, _x);
   }
  }
 }

 double ssm(double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt, double _lv) { 
#if 0
_check_ssm(_p, _ppvar, _thread, _nt);
#endif
 return _n_ssm(_p, _ppvar, _thread, _nt, _lv);
 }

 static double _n_ssm(double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt, double _lv){ int _i, _j;
 double _xi, _theta;
 if (!usetable) {
 return _f_ssm(_p, _ppvar, _thread, _nt, _lv); 
}
 _xi = _mfac_ssm * (_lv - _tmin_ssm);
 if (isnan(_xi)) {
  return _xi; }
 if (_xi <= 0.) {
 return _t_ssm[0];
 }
 if (_xi >= 200.) {
 return _t_ssm[200];
 }
 _i = (int) _xi;
 return _t_ssm[_i] + (_xi - (double)_i)*(_t_ssm[_i+1] - _t_ssm[_i]);
 }

 
double _f_ssm ( _threadargsprotocomma_ double _lv ) {
   double _lssm;
 _lssm = 1.0 / ( 1.0 + exp ( ( _lv + 40.0 ) / ( - 3.0 ) ) ) ;
   
return _lssm;
 }
 
static void _hoc_ssm(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 
#if 1
 _check_ssm(_p, _ppvar, _thread, _nt);
#endif
 _r =  ssm ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 static double _mfac_ssh, _tmin_ssh;
  static void _check_ssh(double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) {
  static int _maktable=1; int _i, _j, _ix = 0;
  double _xi, _tmax;
  if (!usetable) {return;}
  if (_maktable) { double _x, _dx; _maktable=0;
   _tmin_ssh =  vmin ;
   _tmax =  vmax ;
   _dx = (_tmax - _tmin_ssh)/200.; _mfac_ssh = 1./_dx;
   for (_i=0, _x=_tmin_ssh; _i < 201; _x += _dx, _i++) {
    _t_ssh[_i] = _f_ssh(_p, _ppvar, _thread, _nt, _x);
   }
  }
 }

 double ssh(double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt, double _lv) { 
#if 0
_check_ssh(_p, _ppvar, _thread, _nt);
#endif
 return _n_ssh(_p, _ppvar, _thread, _nt, _lv);
 }

 static double _n_ssh(double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt, double _lv){ int _i, _j;
 double _xi, _theta;
 if (!usetable) {
 return _f_ssh(_p, _ppvar, _thread, _nt, _lv); 
}
 _xi = _mfac_ssh * (_lv - _tmin_ssh);
 if (isnan(_xi)) {
  return _xi; }
 if (_xi <= 0.) {
 return _t_ssh[0];
 }
 if (_xi >= 200.) {
 return _t_ssh[200];
 }
 _i = (int) _xi;
 return _t_ssh[_i] + (_xi - (double)_i)*(_t_ssh[_i+1] - _t_ssh[_i]);
 }

 
double _f_ssh ( _threadargsprotocomma_ double _lv ) {
   double _lssh;
 _lssh = 1.0 / ( 1.0 + exp ( ( _lv + 45.0 ) / 3.0 ) ) ;
   
return _lssh;
 }
 
static void _hoc_ssh(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 
#if 1
 _check_ssh(_p, _ppvar, _thread, _nt);
#endif
 _r =  ssh ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ return 2;}
 
static void _ode_spec(NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ena = _ion_ena;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 2; ++_i) {
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
  ena = _ion_ena;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_na_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_na_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_na_sym, _ppvar, 2, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) {
  int _i; double _save;{
  h = h0;
  m = m0;
 {
   m = ssm ( _threadargscomma_ v ) ;
   h = ssh ( _threadargscomma_ v ) ;
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

#if 0
 _check_ssm(_p, _ppvar, _thread, _nt);
 _check_ssh(_p, _ppvar, _thread, _nt);
#endif
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
  ena = _ion_ena;
 initmodel(_p, _ppvar, _thread, _nt);
 }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   g = gbar * ( pow( m , powm ) ) * ( pow( h , powh ) ) ;
   ina = g * ( v - ena ) ;
   }
 _current += ina;

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
  ena = _ion_ena;
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _dina;
  _dina = ina;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dinadv += (_dina - ina)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ina += ina ;
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
  ena = _ion_ena;
 {   states(_p, _ppvar, _thread, _nt);
  } }}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = m_columnindex;  _dlist1[0] = Dm_columnindex;
 _slist1[1] = h_columnindex;  _dlist1[1] = Dh_columnindex;
   _t_ssm = makevector(201*sizeof(double));
   _t_ssh = makevector(201*sizeof(double));
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/Users/sandek/CA1Sim/hh3nax.mod";
static const char* nmodl_file_text = 
  "TITLE HH na channel\n"
  ": Mel-modified Hodgkin - Huxley conductances (after Ojvind et al.)\n"
  ": Updated by K. Archie:\n"
  ":    removed leak current\n"
  ":    changed to derivatives rather than explicit step calculation to\n"
  ":    support NEURON's spiffy, smarter integration\n"
  ": BFB Cleaned (2007)\n"
  ": Aaron Milstein modified 2015\n"
  ": Without slow inactivation for axon\n"
  "\n"
  "NEURON {\n"
  "    SUFFIX hh3nax\n"
  "    USEION na READ ena WRITE ina\n"
  "    RANGE gbar, g\n"
  "    GLOBAL vmin, vmax\n"
  "    GLOBAL taum, tauh\n"
  "    GLOBAL powm, powh\n"
  "}\n"
  "\n"
  "UNITS {\n"
  "    (mA) = (milliamp)\n"
  "    (mV) = (millivolt)\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "    gbar = .20 (mho/cm2)\n"
  "    vmin = -120 (mV)\n"
  "    vmax = 100 (mV)\n"
  "    taum = .05 (ms)\n"
  "    tauh = .5 (ms)\n"
  "    powm = 3\n"
  "    powh = 1\n"
  "}\n"
  "\n"
  "STATE {    \n"
  "    h  <1e-1> \n"
  "    m  <1e-1>\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "    v (mV)\n"
  "    ina (mA/cm2)\n"
  "    ena (mV)\n"
  "    g (mho/cm2)\n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "    m = ssm(v)\n"
  "    h = ssh(v)\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "    SOLVE states METHOD cnexp\n"
  "    g = gbar*(m^powm)*(h^powh)\n"
  "    ina = g*(v - ena)\n"
  "}\n"
  "\n"
  "DERIVATIVE states {\n"
  "    m' = (ssm(v) - m)/taum\n"
  "    h' = (ssh(v) - h)/tauh\n"
  "}\n"
  "\n"
  "FUNCTION ssm(v (mV)) {  : Na activation steady state\n"
  "    TABLE FROM vmin TO vmax WITH 200\n"
  "    ssm = 1/(1 + exp((v + 40 (mV))/(-3 (mV))))\n"
  "}\n"
  "\n"
  "FUNCTION ssh(v (mV)) {  : Na inactivation steady state\n"
  "    TABLE FROM vmin TO vmax WITH 200\n"
  "    ssh = 1/(1 + exp((v + 45 (mV))/3 (mV)))\n"
  "}\n"
  ;
#endif
