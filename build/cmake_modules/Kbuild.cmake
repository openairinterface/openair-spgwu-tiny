# SPDX-License-Identifier: LicenseRef-CSSL-1.0
src=${dir}
obj-m += ${name}.o
${name}-y += ${objs}
ccflags-y += ${module_cc_opt}
