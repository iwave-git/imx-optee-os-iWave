incdirs-y += ../include

srcs-$(CFG_NXP_CAAM_ECC_DRV) += caam_ecc.c
srcs-$(CFG_NXP_CAAM_RSA_DRV) += caam_rsa.c caam_prime_rsa.c
srcs-$(CFG_NXP_CAAM_DH_DRV)  += caam_dh.c
srcs-y += caam_math.c
