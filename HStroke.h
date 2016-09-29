// HStroke.h: interface for the HStroke class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HSTROKE_H__D33B3CC5_37DF_4D35_82D3_515EF16125A0__INCLUDED_)
#define AFX_HSTROKE_H__D33B3CC5_37DF_4D35_82D3_515EF16125A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afxwin.h>
#include <math.h>
enum HPicType{PIC_line, PIC_poly, PIC_ellipse, PIC_rect, PIC_text, PIC_select,PIC,PIC_ARROW};
//My Tracker
class HStrokeTracker : public CRectTracker
{
public:
	int m_picExtra;
	HPicType m_picType;
	HStrokeTracker();
	CRect m_temp_rect ;// 用于存取竖直或者横向直线的坐标
	bool m_b_temp_rect ;//是否开启temp_rect ;
	void Draw( CDC* pDC ) const;
};

class HStroke : public CObject
{
public:
	virtual void ReSize(CRect newPos);
	HStrokeTracker m_tracker;//外边的9个点 
	virtual void Move(int x, int y);
	//attributes
	int m_penStyle;
	int m_penWidth;
	COLORREF m_penColor;
	HPicType m_picType;
	CArray<CPoint, CPoint> m_points;


	//state
	BOOL m_bSelected;
	BOOL m_bHighLight;

	virtual BOOL IsHightLight();
	virtual void SetHighLight(BOOL bHL);
	virtual BOOL IsPointIn(const CPoint &point);
	
	
	virtual void SetCurrentPoint(CPoint point);
	virtual void ReDrawStroke(CDC *pDC, CPoint point);
	virtual void DrawStroke(CDC *pDC);
	virtual void _Draw(CDC *pDC);

	HStroke();
	DECLARE_SERIAL(HStroke)
	virtual ~HStroke();
	virtual void Serialize(CArchive& ar);

};


class HStrokeLine : public HStroke  
{
public:
	HStrokeLine();
	DECLARE_SERIAL(HStrokeLine)
	virtual ~HStrokeLine();
	virtual void SetCurrentPoint(CPoint point);
	virtual void ReDrawStroke(CDC *pDC, CPoint point);
	virtual void DrawStroke(CDC *pDC);
	virtual void _Draw(CDC *pDC);
	
	virtual BOOL IsPointIn(const CPoint &point);
protected:
};
class HStrokeArrow : public HStrokeLine  
{
public:
	HStrokeArrow();
	DECLARE_SERIAL(HStrokeArrow);
	//virtual void SetCurrentPoint(CPoint point);
	//virtual void ReDrawStroke(CDC *pDC, CPoint point);
//	virtual void DrawStroke(CDC *pDC);
	virtual void _Draw(CDC *pDC);
	//virtual BOOL IsPointIn(const CPoint &point);
	void DrawArrowLine(CDC *pDC ,CPoint p1,CPoint p2);
protected:
};


class HStrokePoly : public HStroke  
{
public:
	HStrokePoly();
	DECLARE_SERIAL(HStrokePoly)
	virtual ~HStrokePoly();
	virtual void SetCurrentPoint(CPoint point);
	virtual void ReDrawStroke(CDC *pDC, CPoint point);
	virtual void _Draw(CDC *pDC);
	virtual BOOL IsPointIn(const CPoint &point);
};

class HStrokePic :public HStroke{
public :
	DECLARE_SERIAL(HStrokePic)
	CBitmap m_bitmap ; 
	int m_nHeight; 
	int m_nWidth ;
	CDC *m_pMemDC;
public :
	HStrokePic();
	//virtual BOOL IsHightLight();
	//virtual void SetHighLight(BOOL bHL);
	virtual BOOL IsPointIn(const CPoint &point);
	virtual void SetCurrentPoint(CPoint point);
	virtual void ReDrawStroke(CDC *pDC, CPoint point);
	virtual void DrawStroke(CDC *pDC);
	virtual void _Draw(CDC *pDC);
	void ReSize(CRect newPos);

};
class HStrokeRect : public HStrokeLine  
{
public:
	DECLARE_SERIAL(HStrokeRect)
	HStrokeRect();
	virtual ~HStrokeRect();
	virtual void ReDrawStroke(CDC *pDC, CPoint point);
	virtual void _Draw(CDC *pDC);
	virtual BOOL IsPointIn(const CPoint &point);

};


class HStrokeEllipse : public HStrokeLine 
{
public:
	HStrokeEllipse();
	DECLARE_SERIAL(HStrokeEllipse)
	virtual ~HStrokeEllipse();
	virtual void ReDrawStroke(CDC *pDC, CPoint point);
	virtual void _Draw(CDC *pDC);
	virtual BOOL IsPointIn(const CPoint &point);
};



class HStrokeText : public HStrokeLine  
{
public:
	HStrokeText();
	HStrokeText(CString info);
	DECLARE_SERIAL(HStrokeText)
	virtual ~HStrokeText();
	virtual void ReDrawStroke(CDC *pDC, CPoint point);
	virtual void DrawStroke(CDC *pDC);
	virtual void Serialize(CArchive& ar);

	CString m_text;
};
class HStrokeSelect : public HStrokeRect
{
public:
	HStrokeSelect();
	virtual void DrawStroke(CDC *pDC);
};
#endif // !defined(AFX_HSTROKE_H__D33B3CC5_37DF_4D35_82D3_515EF16125A0__INCLUDED_)
