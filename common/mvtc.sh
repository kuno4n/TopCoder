#!/bin/sh
#
# @(#) mvtc.sh 20121005
#
# 引数 $1：Arenaディレクトリから移動するソースファイル名
# 引数 $2：SRM番号
# 引数 $3：軍
# 引数 $4：問題得点
#
##################################################

if [ $# -ne 4 ]; then
  echo "Usage: mvtc src_name srm_num div value" 1>&2
  exit 1
fi
mkdir /Users/kuno4n/github/TopCoder/src/$2-div$3-$4
mv $1 /Users/kuno4n/github/TopCoder/src/$2-div$3-$4
