TITLE Ca channels (T, N, L-type) for CA1 Pyramidal Neurons

NEURON {
	SUFFIX Ca3
	USEION ca READ eca WRITE ica
	RANGE gtcabar, gncabar, glcabar, gtca, gnca, glca
	RANGE ainf, taua, binf, taub, gbar, gcamult, i
	GLOBAL Vshift, q10, temp
}

UNITS {
	(molar) = (1/liter)
	(mM)    = (millimolar)
	(mV)    = (millivolt)
	(mA)    = (milliamp)
	(S)     = (siemens)
}

PARAMETER {
	: Conductance values adjusted for CA1 Pyramidal Neurons (S/cm2)
	gtcabar = 0.0001    (S/cm2)   : T-type (Low-threshold, distally expressed)
	gncabar = 0.0010    (S/cm2)   : N-type (High-threshold, synaptic/somatic)
	glcabar = 0.0030    (S/cm2)   : L-type (High-threshold, somatic/proximal)
	
	gcamult = 1.
	Vshift  = 0         (mV)
	temp    = 24        (degC)    : Base reference temp for kinetics
	q10     = 3.0                 : Q10 rate scaling multiplier
}

ASSIGNED {
	v       (mV)
	eca     (mV)
	ica     (mA/cm2)
	i       (mA/cm2)
	gtca    (S/cm2)
	gnca    (S/cm2)
	glca    (S/cm2)
	gbar    (S/cm2)
	celsius (degC)
	taua    (ms)
	ainf
	taub    (ms)
	binf
	qt
}

STATE {
	a 
	b 
	c 
	d 
	e
}

BREAKPOINT {
	SOLVE state METHOD cnexp
	gtca = gtcabar * gcamult * a * a * b
	gnca = gncabar * gcamult * c * c * d
	glca = glcabar * gcamult * e * e
	ica = (gtca + gnca + glca) * (v - eca)
	i = ica
}

DERIVATIVE state {
	rates(v)
	a' = (ainf - a) / taua
	b' = (binf - b) / taub
	c' = (alphac(v) * (1 - c) - betac(v) * c) * qt
	d' = (alphad(v) * (1 - d) - betad(v) * d) * qt
	e' = (alphae(v) * (1 - e) - betae(v) * e) * qt
}

INITIAL {
	qt = q10^((celsius - temp)/10)
	rates(v)
	a = ainf
	b = binf
	c = alphac(v) / (alphac(v) + betac(v))
	d = alphad(v) / (alphad(v) + betad(v))
	e = alphae(v) / (alphae(v) + betae(v))
	gbar = gcamult * (gtcabar + gncabar + glcabar)
	gtca = gtcabar * gcamult * a * a * b
	gnca = gncabar * gcamult * c * c * d
	glca = glcabar * gcamult * e * e
	ica = (gtca + gnca + glca) * (v - eca)
	i = ica
}

FUNCTION rates(v (mV)) {
	LOCAL v_shift
	v_shift = v + Vshift
	
	ainf = alphaa(v_shift) / (alphaa(v_shift) + betaa(v_shift))
	taua = (1 / (alphaa(v_shift) + betaa(v_shift))) / qt
	
	binf = alphab(v_shift) / (alphab(v_shift) + betab(v_shift))
	taub = (1 / (alphab(v_shift) + betab(v_shift))) / qt
}

FUNCTION alphaa(v (mV)) (/ms) {
	alphaa = f(2, 0.1, v, 19.26)
}

FUNCTION betaa(v (mV)) (/ms) {
	betaa = exponential(0.009, -0.045393, v, 0)
}

FUNCTION alphab(v (mV)) (/ms) {
	alphab = exponential(1e-6, -0.061501, v, 0)
}

FUNCTION betab(v (mV)) (/ms) {
	betab = logistic(1, -0.1, v, 29.79)
}

FUNCTION alphac(v (mV)) (/ms) {
	alphac = f(1.9, 0.1, v, 19.88)
}

FUNCTION betac(v (mV)) (/ms) {
	betac = exponential(0.046, -0.048239, v, 0)
}

FUNCTION alphad(v (mV)) (/ms) {
	alphad = exponential(1.6e-4, -0.020661, v, 0)
}

FUNCTION betad(v (mV)) (/ms) {
	betad = logistic(1, -0.1, v, 39)
}

FUNCTION alphae(v (mV)) (/ms) {
	alphae = f(156.9, 0.1, v, 81.5)
}

FUNCTION betae(v (mV)) (/ms) {
	betae = exponential(0.29, -0.092081, v, 0)
}

FUNCTION f(A, k, v (mV), D) (/ms) {
	LOCAL x
	x = k * (v - D)
	if (fabs(x) > 1e-6) {
		f = A * x / (1 - exp(-x))
	} else {
		f = A * (1 + 0.5 * x)
	}
}

FUNCTION logistic(A, k, v (mV), D) (/ms) {
	logistic = A / (1 + exp(k * (v - D)))
}

FUNCTION exponential(A, k, v (mV), D) (/ms) {
	exponential = A * exp(k * (v - D))
}