#!/bin/bash
# Copyright 2022 NXP
set -euo pipefail

boards_list=(
	imx-mx6dhmbedge \
	imx-mx6dlsabreauto \
	imx-mx6dlsabresd \
	imx-mx6dlhmbedge \
	imx-mx6qsabrelite \
	imx-mx6qsabresd \
	imx-mx6qsabreauto
	imx-mx6qhmbedge \
	imx-mx6qpsabresd \
	imx-mx6qpsabreauto \
	imx-mx6shmbedge \
	imx-mx6slevk \
	imx-mx6sllevk \
	imx-mx6solosabresd \
	imx-mx6solosabreauto \
	imx-mx6sxsabreauto \
	imx-mx6sxsabresd \
	imx-mx6sxudooneofull \
	imx-mx6ulevk \
	imx-mx6ul9x9evk \
	imx-mx6ulccimx6ulsbcpro\
	imx-mx6ullevk \
	imx-mx6ulzevk \
	imx-mx7dsabresd \
	imx-mx7dpico_mbl \
	imx-mx7swarp7 \
	imx-mx7swarp7_mbl \
	imx-mx7dclsom \
	imx-mx7ulpevk \
	imx-mx8dxmek \
	imx-mx8mqevk \
	imx-mx8mmevk \
        imx-mx8mm_iwg34m \
        imx-mx8mm_iwg34m_2gb \
        imx-mx8mm_iwg34s \
        imx-mx8mm_iwg34s_2gb \
        imx-mx8mm_iwg34s_4gb \
        imx-mx8mm_iwg34s_8gb \
        imx-mx8mm_iwg34m_q7 \
        imx-mx8mm_iwg34m_q7_2gb \
	imx-mx8mnevk \
        imx-mx8mn_iwg37m \
        imx-mx8mn_iwg37m_2gb \
        imx-mx8mn_iwg37s \
        imx-mx8mn_iwg37m_q7 \
	imx-mx8mpevk \
	imx-mx8qxpmek \
	imx-mx8qmmek \
	imx-mx8qmmekcockpita53 \
	imx-mx8qmmekcockpita72 \
	imx-mx8dxlevk \
	imx-mx8ulpevk \
	ls-ls1021atwr \
	ls-ls1021aqds \
	ls-ls1012ardb \
	ls-ls1012afrwy \
	ls-ls1043ardb \
	ls-ls1046ardb \
	ls-ls1088ardb \
	ls-ls2088ardb \
	ls-lx2160ardb \
)

CROSS_COMPILE="${CROSS_COMPILE:-arm-linux-gnueabihf-}"
CROSS_COMPILE64="${CROSS_COMPILE64:-aarch64-linux-gnu-}"
O="${O:-.}"
NB_CORES="${NB_CORES:-$(grep -c processor /proc/cpuinfo)}"
CFG_TEE_CORE_LOG_LEVEL="${CFG_TEE_CORE_LOG_LEVEL:-1}"
CFG_TEE_TA_LOG_LEVEL="${CFG_TEE_TA_LOG_LEVEL:-0}"

function usage()
{
	cat << EOF
Usage: $(basename "$0") [all] [all-silence] [list] [<board>]
	all          compile all platform supported
	list         list of supported platforms
	<board>      build the given platform
EOF
}

# Build the board given in parameter $1
function build()
{
	local plat="$1"

	# Generate the uTee binary for armv7 platforms
	if [[ "$plat" == *mx[6-7]* ]];
	then
		# Compile the tee.bin for all platforms
		make -j"$NB_CORES" \
			CROSS_COMPILE="$CROSS_COMPILE" \
			CROSS_COMPILE64="$CROSS_COMPILE64" \
			CFG_TEE_CORE_LOG_LEVEL="$CFG_TEE_CORE_LOG_LEVEL" \
			CFG_TEE_TA_LOG_LEVEL="$CFG_TEE_TA_LOG_LEVEL" \
			CFG_WERROR=y \
			PLATFORM="$plat" \
			O="$O"/build."$plat" \
			all uTee || exit 1
	else
		make -j"$NB_CORES" \
			CROSS_COMPILE="$CROSS_COMPILE" \
			CROSS_COMPILE64="$CROSS_COMPILE64" \
			CFG_TEE_CORE_LOG_LEVEL="$CFG_TEE_CORE_LOG_LEVEL" \
			CFG_TEE_TA_LOG_LEVEL="$CFG_TEE_TA_LOG_LEVEL" \
			CFG_WERROR=y \
			PLATFORM="$plat" \
			O="$O"/build."$plat" \
			all || exit 1
	fi
}

function build_all()
{
	start=$(date +%s)
	for b in "${boards_list[@]}"
	do
		echo "=============Building ""$b""================"

		build "$b"
	done
	end=$(date +%s)
	echo "Compilation time ""$((end-start))"" seconds"
}

function list_board()
{
	for b in "${boards_list[@]}"
	do
		echo "$b"
	done
}

# Main
[[ $# -eq 0 ]] && usage && exit 1
[[ "$1" == "help" ]] && usage && exit 0
[[ "$1" == "list" ]] && list_board && exit 0
[[ "$1" == "all" ]] && build_all && exit 0

for b in "$@"
do
	build "$b"
done

exit 0
