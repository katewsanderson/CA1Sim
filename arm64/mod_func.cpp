#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;
#if defined(__cplusplus)
extern "C" {
#endif

extern void _ampa_kin_reg(void);
extern void _ampa_kin2_reg(void);
extern void _Aradi_Ca_reg(void);
extern void _Aradi_Ca2_reg(void);
extern void _Aradi_CadepK_reg(void);
extern void _Aradi_CadepK2_reg(void);
extern void _Ca_Accum_reg(void);
extern void _exp2EPSG_NMDA_reg(void);
extern void _exp2EPSG_reg(void);
extern void _gaba_a_kin_reg(void);
extern void _h_reg(void);
extern void _hh3k_reg(void);
extern void _hh3na_reg(void);
extern void _hh3nax_reg(void);
extern void _kad_reg(void);
extern void _kap_reg(void);
extern void _kdr_reg(void);
extern void _km_orig_reg(void);
extern void _km2_reg(void);
extern void _km3_reg(void);
extern void _nas_reg(void);
extern void _nax_reg(void);
extern void _nmda_kin_reg(void);
extern void _nmda_kin2_reg(void);
extern void _nmda_kin3_reg(void);
extern void _nmda_kin4_reg(void);
extern void _nmda_kin5_reg(void);
extern void _pr_reg(void);
extern void _pr2_reg(void);
extern void _vecevent_reg(void);

void modl_reg() {
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");
    fprintf(stderr, " \"ampa_kin.mod\"");
    fprintf(stderr, " \"ampa_kin2.mod\"");
    fprintf(stderr, " \"Aradi_Ca.mod\"");
    fprintf(stderr, " \"Aradi_Ca2.mod\"");
    fprintf(stderr, " \"Aradi_CadepK.mod\"");
    fprintf(stderr, " \"Aradi_CadepK2.mod\"");
    fprintf(stderr, " \"Ca_Accum.mod\"");
    fprintf(stderr, " \"exp2EPSG_NMDA.mod\"");
    fprintf(stderr, " \"exp2EPSG.mod\"");
    fprintf(stderr, " \"gaba_a_kin.mod\"");
    fprintf(stderr, " \"h.mod\"");
    fprintf(stderr, " \"hh3k.mod\"");
    fprintf(stderr, " \"hh3na.mod\"");
    fprintf(stderr, " \"hh3nax.mod\"");
    fprintf(stderr, " \"kad.mod\"");
    fprintf(stderr, " \"kap.mod\"");
    fprintf(stderr, " \"kdr.mod\"");
    fprintf(stderr, " \"km_orig.mod\"");
    fprintf(stderr, " \"km2.mod\"");
    fprintf(stderr, " \"km3.mod\"");
    fprintf(stderr, " \"nas.mod\"");
    fprintf(stderr, " \"nax.mod\"");
    fprintf(stderr, " \"nmda_kin.mod\"");
    fprintf(stderr, " \"nmda_kin2.mod\"");
    fprintf(stderr, " \"nmda_kin3.mod\"");
    fprintf(stderr, " \"nmda_kin4.mod\"");
    fprintf(stderr, " \"nmda_kin5.mod\"");
    fprintf(stderr, " \"pr.mod\"");
    fprintf(stderr, " \"pr2.mod\"");
    fprintf(stderr, " \"vecevent.mod\"");
    fprintf(stderr, "\n");
  }
  _ampa_kin_reg();
  _ampa_kin2_reg();
  _Aradi_Ca_reg();
  _Aradi_Ca2_reg();
  _Aradi_CadepK_reg();
  _Aradi_CadepK2_reg();
  _Ca_Accum_reg();
  _exp2EPSG_NMDA_reg();
  _exp2EPSG_reg();
  _gaba_a_kin_reg();
  _h_reg();
  _hh3k_reg();
  _hh3na_reg();
  _hh3nax_reg();
  _kad_reg();
  _kap_reg();
  _kdr_reg();
  _km_orig_reg();
  _km2_reg();
  _km3_reg();
  _nas_reg();
  _nax_reg();
  _nmda_kin_reg();
  _nmda_kin2_reg();
  _nmda_kin3_reg();
  _nmda_kin4_reg();
  _nmda_kin5_reg();
  _pr_reg();
  _pr2_reg();
  _vecevent_reg();
}

#if defined(__cplusplus)
}
#endif
