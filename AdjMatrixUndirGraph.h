#ifndef __ADJ_MATRIX_UNDIR_GRAPH_H__
#define __ADJ_MATRIX_UNDIR_GRAPH_H__
# include"Assistance.h"
// ???????????????
template <class ElemType>
class AdjMatrixUndirGraph 
{
protected:
// ?????????????:
	int vexNum, vexMaxNum, arcNum;			// ?????????????????????????????
	int **arcs;							    // ?????????????
	ElemType *vertexes;						// ??????????????? 
	mutable Status *tag;					// ???????

public:
// ??????????????????:
	AdjMatrixUndirGraph(ElemType es[], int vertexNum, int vertexMaxNum = DEFAULT_SIZE);	
		// ??????es[]?????,????????vertexNum,????????????????vertexMaxNum,?????0???????
	AdjMatrixUndirGraph(int vertexMaxNum = DEFAULT_SIZE);	
		// ????????????????????vertexMaxNum,?????0???????
	~AdjMatrixUndirGraph();					// ????????
	void Clear();			              // ????			 
	bool IsEmpty();                 // ?º�????????????? 
	int GetOrder(ElemType &d) const;// ???????	
	Status GetElem(int v, ElemType &d) const;// ????????	
	Status SetElem(int v, const ElemType &d);// ????????????
	int GetVexNum() const;					// ??????????			 
	int GetArcNum() const;					// ???????			 
	int FirstAdjVex(int v) const;		// ???????v??????????			 
	int NextAdjVex(int v1, int v2) const;		 // ???????v1???????v2???????????			 
	void InsertVex(const ElemType &d);			 // ?????????d?????		 
	void InsertArc(int v1, int v2,int w);			     // ???????v1??v2???			 
	void DeleteVex(const ElemType &d);			 // ????????d?????			 
	void DeleteArc(int v1, int v2);			     // ????????v1??v2???			 
	Status GetTag(int v) const;			         // ???????v????		 
	void SetTag(int v, Status val) const;	   // ???????v?????val		 
	AdjMatrixUndirGraph(const AdjMatrixUndirGraph<ElemType> &g);	// ?????????
	AdjMatrixUndirGraph<ElemType> &operator =(const AdjMatrixUndirGraph<ElemType> &g); 
		// ??????????
  	void Display();	                         // ??????????????
	int GetCountOutDegree(ElemType &d)const;
	int GetCountInDegree(ElemType &d)const;
	Status GetNeighborNode(ElemType &d)const;
	Status GetCricle()const;
};

// ??????????????????????
template<class ElemType>
Status AdjMatrixUndirGraph<ElemType>::GetCricle()const
{
	//check if dir-circle in Matrix
	if (vexNum == 0)
		{	
		cout<<"This Is Empty !";
		return SUCCESS;
		}
	
	cout<<"Circle: ";
	for (int i=0;i<vexNum;i++)
	{
		if (arcs[i][i]!= 0)
			cout<<vertexes[i]<<"\t";
	}

	return SUCCESS;
}
template<class ElemType>
Status AdjMatrixUndirGraph<ElemType>::GetNeighborNode(ElemType &d)const
{
	int i;
	for (i=0;i<vexNum;i++)
	{
		if (vertexes[i]==d)
				break;
	}
	if (i == vexNum)
		throw Error("not in Matrix");

	for (int j=0;j<vexNum;j++)
		{
			//print all neighbornodes in " A ->B	"
			if (arcs[i][j] != 0)
				cout<<d<<" ->"<<vertexes[j]<<"\t";
		}

	return SUCCESS;
}

template<class ElemType> 
int AdjMatrixUndirGraph<ElemType>::GetCountOutDegree(ElemType &d)const
{
	int i;
	for (i=0 ;i<vexNum;i++)
		{
			if (vertexes[i]==d)
				break;
		}
	// ????????ª─?∙z d ????
	if (i == vexNum)
		return -1 ;
	int sum=0;

	for (int j=0;j<vexNum;j++)
		{
			if (arcs[i][j] != 0)
				sum++;
		}
	return sum;
}

template<class ElemType> 
int AdjMatrixUndirGraph<ElemType>::GetCountInDegree(ElemType &d)const
{
	int i;
	for (i=0 ;i<vexNum;i++)
		{
			if (vertexes[i]==d)
				break;
		}
	// ????????ª─?∙z d ????
	if (i == vexNum)
		return -1 ;
	
	int sum=0;
	for (int j=0;j<vexNum;j++)
		{
			if (arcs[j][i] != 0)
				sum++;
		}
	return sum;
}

template <class ElemType>
AdjMatrixUndirGraph<ElemType>::AdjMatrixUndirGraph(ElemType es[], int vertexNum, int vertexMaxNum)
// ?????????????????????es[],????????vertexNum,????????????????vertexMaxNum,?????0???????

{
	if (vertexMaxNum < 0)
    	throw Error("??????????????????????!");        // ?????

	if (vertexMaxNum < vertexNum)
    	throw Error("?????????????????????????????!");// ?????

	vexNum = vertexNum;			
	vexMaxNum = vertexMaxNum; 
	arcNum = 0;	

	vertexes = new ElemType[vexMaxNum];      // ??????????????????
	tag = new Status[vexMaxNum];			       // ??????????
	arcs = (int **)new int *[vexMaxNum];     // ??????????
	for (int v = 0; v < vexMaxNum; v++) 
		arcs[v] = new int[vexMaxNum];	

	for (int v = 0; v < vexNum; v++) {
		vertexes[v] = es[v];
		tag[v] = UNVISITED;
		for (int u = 0; u < vexNum; u++)
			arcs[v][u] = 0;
	}
}

template <class ElemType>
AdjMatrixUndirGraph<ElemType>::AdjMatrixUndirGraph(int vertexMaxNum)
// ?????????????????????????????vertexMaxNum????????
{
	if (vertexMaxNum < 0)
    	throw Error("??????????????????????!");// ?????

	vexNum = 0;			
	vexMaxNum = vertexMaxNum;
	arcNum = 0;	

	vertexes = new ElemType[vexMaxNum];     // ??????????????????
	tag = new Status[vexMaxNum];			      // ??????????
	arcs = (int **)new int *[vexMaxNum];    // ??????????
	for (int v = 0; v < vexMaxNum; v++) 
		arcs[v] = new int[vexMaxNum];	
 }

template <class ElemType>
void AdjMatrixUndirGraph<ElemType>::Clear()
// ?????????????????????????????????0.			 
{
    vexNum = 0;
	arcNum = 0;	
}

template <class ElemType>
bool AdjMatrixUndirGraph<ElemType>::IsEmpty()
// ???????????????????????true,?????false.
{
	return vexNum == 0;
}

template <class ElemType>
AdjMatrixUndirGraph<ElemType>::~AdjMatrixUndirGraph()
// ???????????????????????
{
	delete []vertexes;					// ??????????
	delete []tag;						    // ?????

	for (int v = 0; v < vexMaxNum; v++)	// ????????????
		delete []arcs[v];
	delete []arcs;					    // ?????????
}

template <class ElemType>
int AdjMatrixUndirGraph<ElemType>::GetOrder(ElemType &d) const
// ????????????d?????.?????????0???????º�?????????d???????-1. 
{
    for (int v = 0; v < vexNum; v++){
		    if (vertexes[v] == d)
		   return v;	    // ????d????,??????????? 
		}
	return -1;	        // ????d??????,????-1
}	

template <class ElemType>
Status AdjMatrixUndirGraph<ElemType>::GetElem(int v, ElemType &d) const
// ???????????????v??????, v??????ª�??0 ?? v ?? vexNum, v????????
// ???d???????????????ENTRY_FOUND????????????NOT_PRESENT
{
	if (v < 0 || v >= vexNum)
		return NOT_PRESENT;	// v??ª�???,????????????
	else	{
		d = vertexes[v];	  // ??????v??????????d
		return ENTRY_FOUND;	// ??????????
	}
}	

template <class ElemType>
Status AdjMatrixUndirGraph<ElemType>::SetElem(int v, const ElemType &d)
// ?????????????????????v??????ª�??0 ?? v ?? vexNum, v????????????
//	SUCCESS, ??????????RANGE_ERROR
{
	if (v < 0 || v >= vexNum)
		return RANGE_ERROR;	// v??ª�???,????ª�????
	else	{
		vertexes[v] = d;		// ??????????????d 
		return SUCCESS;		  // ?????????
	}
}

template <class ElemType>
int AdjMatrixUndirGraph<ElemType>::GetVexNum() const
// ???????????????????			 
{
	return vexNum;
}

template <class ElemType>
int AdjMatrixUndirGraph<ElemType>::GetArcNum() const
// ????????????????
{
	return arcNum;
}		 

template <class ElemType>
int AdjMatrixUndirGraph<ElemType>::FirstAdjVex(int v) const
// ????????????????v???1??????????		 
{
	if (v < 0 || v >= vexNum)
       throw Error("v?????!");// ?????

	for (int u = 0; u < vexNum; u++)
		if (arcs[v][u] != 0)
       return u;

	return -1;					// ????-1?????????
}

template <class ElemType>
int AdjMatrixUndirGraph<ElemType>::NextAdjVex(int v1, int v2) const
// ????????????????v1???????v2???????????			 
{
	if (v1 < 0 || v1 >= vexNum)
       throw Error("v1?????!");	// ?????
	if (v2 < 0 || v2 >= vexNum)
       throw Error("v2?????!");	// ?????
	if (v1 == v2) throw
       Error("v1???????v2!");		// ?????

	for (int u = v2 + 1; u < vexNum; u++)
		if (arcs[v1][u] != 0)
       return u;

	return -1;						// ????-1??????????????
}

template <class ElemType>
void AdjMatrixUndirGraph<ElemType>::InsertVex(const ElemType &d)
// ???????????????d			 
{
	if (vexNum == vexMaxNum)
    throw Error("??????????????????????????!");	// ?????

	vertexes[vexNum] = d;
	tag[vexNum] = UNVISITED;
	for (int v = 0; v <= vexNum; v++) {
		arcs[vexNum][v] = 0;
		arcs[v][vexNum] = 0;
  }
  vexNum++;
}

template <class ElemType>
void AdjMatrixUndirGraph<ElemType>::InsertArc(int v1, int v2, int w)
// ?????????????????????v1??v2???			 
{
	if (v1 < 0 || v1 >= vexNum)
    throw Error("v1?????!");	// ?????
	if (v2 < 0 || v2 >= vexNum)
    throw Error("v2?????!");	// ?????
	if (v1 == v2)
    throw Error("v1???????v2!");// ?????

	if (arcs[v1][v2] == 0)	{	  // ??????????º�??(v1, v2) 
	   arcNum++;
	   arcs[v1][v2] = w;	
       
    }
}

template <class ElemType>
void AdjMatrixUndirGraph<ElemType>::DeleteVex(const ElemType &d)
// ????????????????d?????			 
{
   int v;
   for (v = 0; v < vexNum; v++)
     if	(vertexes[v] == d)
        break;
   if (v == vexNum)
      throw Error("??º�???????????????!");	// ?????

   for (int u = 0; u < vexNum; u++)             // ???????d???????? 
	  if (arcs[v][u] == 1) { 
		arcNum--;
	    arcs[v][u] = 0;	
        arcs[u][v] = 0;	
    } 
	      
   vexNum--; 
   if (v < vexNum) {
      vertexes[v] = vertexes[vexNum];
	  tag[v] = tag[vexNum];
	  for (int u = 0; u <= vexNum; u++) 
		 arcs[v][u] = arcs[vexNum][u];
	  for (int u = 0; u <= vexNum; u++) 
         arcs[u][v] = arcs[u][vexNum];
   } 
}

template <class ElemType>
void AdjMatrixUndirGraph<ElemType>::DeleteArc(int v1, int v2)
// ????????????????????v1??v2???			 
{
	if (v1 < 0 || v1 >= vexNum)
    throw Error("v1?????!");	// ?????
	if (v2 < 0 || v2 >= vexNum)
    throw Error("v2?????!");	// ?????
	if (v1 == v2)
    throw Error("v1???????v2!");// ?????

	if (arcs[v1][v2] != 0)	{	// ???????????(v1, v2)
		arcNum--;
	    arcs[v1][v2] = 0;	
    
    } 
}

template <class ElemType>
Status AdjMatrixUndirGraph<ElemType>::GetTag(int v) const
// ????????????????v????		 
{
	if (v < 0 || v >= vexNum)
    throw Error("v?????!");	// ?????

	return tag[v];
}

template <class ElemType>
void AdjMatrixUndirGraph<ElemType>::SetTag(int v, Status val) const 
// ????????????????v?????val		 
{
	if (v < 0 || v >= vexNum)
    throw Error("v?????!");	// ?????

	tag[v] = val;
}

template <class ElemType>
AdjMatrixUndirGraph<ElemType>::AdjMatrixUndirGraph(const AdjMatrixUndirGraph<ElemType> &g)
// ????????????????????????g???????????????????g?????????????
{
	vexNum = g.vexNum;	
	vexMaxNum = g.vexMaxNum;
	arcNum = g.arcNum;	
	
	vertexes = new ElemType[vexMaxNum];		// ???????????????
	tag = new Status[vexMaxNum];			// ??????????
	arcs = (int **)new int *[vexMaxNum];	// ??????????
	for (int v = 0; v < vexMaxNum; v++) 
		arcs[v] = new int[vexMaxNum];	

	for (int v = 0; v < vexNum; v++)	{	// ???????????????
		vertexes[v] = g.vertexes[v];
		tag[v] = g.tag[v];
		for (int u = 0; u < vexNum; u++)
			arcs[v][u] = g.arcs[v][u];
	}
}

template <class ElemType>
AdjMatrixUndirGraph<ElemType> &AdjMatrixUndirGraph<ElemType>::operator =(const AdjMatrixUndirGraph<ElemType> &g)
// ????????????????????????g????????????????????????????????
{
	if (&g != this)	{
	  delete []vertexes;				// ??????????
	  delete []tag;						  // ?????

	  for (int v = 0; v < vexMaxNum; v++)	// ????????????
       delete []arcs[v];
    delete []arcs;					  // ?????????
	  vexNum = g.vexNum;	
    vexMaxNum = g.vexMaxNum;
	  arcNum = g.arcNum;	
	
	  vertexes = new ElemType[vexMaxNum];	 // ???????????????
	  tag = new Status[vexMaxNum];			   // ??????????
	  arcs = (int **)new int *[vexMaxNum]; // ??????????
	  for (int v = 0; v < vexMaxNum; v++) 
		  arcs[v] = new int[vexMaxNum];	

	  for (int v = 0; v < vexNum; v++)	{	 // ???????????????
		  vertexes[v] = g.vertexes[v];
		  tag[v] = g.tag[v];
		  for (int u = 0; u < vexNum; u++)
		    arcs[v][u] = g.arcs[v][u];
	  }
	}
	return *this;
}

template <class ElemType>
void AdjMatrixUndirGraph<ElemType>::Display()
// ???????: ??????????????
{
              
	for (int v = 0; v < vexNum; v++)
 		cout << "\t" << vertexes[v];
	cout << endl;

	for (int v = 0; v < vexNum; v++)	{
		cout << vertexes[v];
		for (int u = 0; u < vexNum; u++)
 			cout << "\t" << arcs[v][u];
		cout << endl;
	}
}

#endif
