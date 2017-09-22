#ifndef LIONHEART_H
#define LIONHEART_H
#include "unit.h"


#include "ajl.h"
#include "ala.h"
#include "alb.h"
#include "alk.h"
#include "ams.h"
#include "apv.h"
#include "art.h"
#include "avg.h"
#include "bac.h"
#include "bag.h"
#include "bbl.h"
#include "big.h"
#include "bmf.h"
#include "cac.h"
#include "car.h"
#include "cbf.h"
#include "cdo.h"
#include "cea.h"
#include "chi.h"
#include "cjc.h"
#include "cjh.h"
#include "cph.h"
#include "csc.h"
#include "djh.h"
#include "dmb.h"
#include "dmc.h"
#include "dog.h"
#include "dpd.h"
#include "dtr.h"
#include "dut.h"
#include "dws.h"
#include "ead.h"
#include "eam.h"
#include "guy.h"
#include "hol.h"
#include "jak.h"
#include "jam.h"
#include "jbj.h"
#include "jdd.h"
#include "jdj.h"
#include "jfk.h"
#include "jkl.h"
#include "jrw.h"
#include "jsy.h"
#include "jtc.h"
#include "kjd.h"
#include "kjh.h"
#include "kkf.h"
#include "kkk.h"
#include "kld.h"
#include "kmg.h"
#include "ksa.h"
#include "ksj.h"
#include "ktf.h"
#include "led.h"
#include "ljk.h"
#include "lkb.h"
#include "lvb.h"
#include "mas.h"
#include "mbm.h"
#include "mbw.h"
#include "mdr.h"
#include "mel.h"
#include "mje.h"
#include "msb.h"
#include "msc.h"
#include "mtj.h"
#include "njy.h"
#include "npt.h"
#include "nra.h"
#include "nts.h"
#include "nwr.h"
#include "odp.h"
#include "ooo.h"
#include "pat.h"
#include "per.h"
#include "rdb.h"
#include "rmt.h"
#include "rnc.h"
#include "rob.h"
#include "sea.h"
#include "sfz.h"
#include "spd.h"
#include "srp.h"
#include "sup.h"
#include "swl.h"
#include "tad.h"
#include "tar.h"
#include "tcr.h"
#include "tds.h"
#include "tks.h"
#include "tmh.h"
#include "tyd.h"
#include "wal.h"
#include "wlf.h"
#include "xgx.h"
#include "zdr.h"
#include "zjh.h"
#include "zps.h"
#include "ogo.h"
#include "tjt.h"
#include "mcr.h"
#include "FNX.h"
#include "nss.h"


#include "lionheart2.h"

using namespace std;

struct Box{
	int minr;
	int maxr;
	int minc;
	int maxc;
};

bool noPlay[NUMTLAS]={
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0
};

static const string tlalist[NUMTLAS]={
"ajl",
"ala",
"alb",
"alk",
"ams",
"apv",
"art",
"avg",
"bac",
"bag",
"bbl",
"big",
"bmf",
"cac",
"car",
"cbf",
"cdo",
"cea",
"chi",
"cjc",
"cjh",
"cph",
"csc",
"djh",
"dmb",
"dmc",
"dog",
"dpd",
"dtr",
"dut",
"dws",
"ead",
"eam",
"guy",
"hol",
"jak",
"jam",
"jbj",
"jdd",
"jdj",
"jfk",
"jkl",
"jrw",
"jsy",
"jtc",
"kjd",
"kjh",
"kkf",
"kkk",
"kld",
"kmg",
"ksa",
"ksj",
"ktf",
"led",
"ljk",
"lkb",
"lvb",
"mas",
"mbm",
"mbw",
"mdr",
"mel",
"mje",
"msb",
"msc",
"mtj",
"njy",
"npt",
"nra",
"nts",
"nwr",
"odp",
"ooo",
"pat",
"per",
"rdb",
"rmt",
"rnc",
"rob",
"sea",
"sfz",
"spd",
"srp",
"sup",
"swl",
"tad",
"tar",
"tcr",
"tds",
"tks",
"tmh",
"tyd",
"wal",
"wlf",
"xgx",
"zdr",
"zjh",
"zps",
"ogo",
"tjt",
"mcr",
"FNX",
"nss",
};
#endif
