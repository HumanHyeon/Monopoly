#define ABUILDING_MAX 24
#define BULD_MAX 3

void build();

typedef struct build
{
	char *name;
	int price;
	int build_state;		//건물 갯수
	int state;				//
	int owner;
}BUILD;

BUILD building[ABUILDING_MAX];

void build()
{
	int j = 0;

	building[0].name = "시작";		building[1].name = "  멕시코";		building[2].name = "   쿠바";	building[3].name = "   칠레";	building[4].name = "  브라질";		building[5].name = "   페루";	building[6].name = " 콜롬비아";
	building[7].name = "무인도";		building[8].name = "  미국";			building[9].name = " 캐나다";	building[10].name = "그린란드";	building[11].name = "뉴질랜드";		building[12].name = "  터키";
	building[13].name = "비행기";	building[14].name = " 러시아";		building[15].name = "  중국";	building[16].name = "  한국";	building[17].name = "  일본";		building[18].name = "  인도";
	building[19].name = "보너스";	building[20].name = " 그리스";		building[21].name = " 프랑스";	building[22].name = "  영국";	 building[23].name = "  파산";		building[24].name = "  독일";

	for (int i = 0; i < ABUILDING_MAX; i++)
	{
		building[i].price = 0;
		building[i].state = 0;
		building[i].owner = 0;
		building[i].build_state = 0;
	}

	j = 20;
	for (int i = 1; i < ABUILDING_MAX; i++)
	{
		if (i == 6 || i == 12 || i == 18 || i == 22)
			continue;
		building[i].price = j;
		j++;
	}
}
