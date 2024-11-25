#ifndef	ORANGES_STRING_H
#define	ORANGES_STRING_H

PUBLIC	void*	memcpy(void* pDst,void* pSrc,int iSize);
PUBLIC	void		memset(void* p_dst, char ch, int size);	
PUBLIC	int		strlen(char* p_str);

#define	phys_copy	memcpy
#define	phys_set	memset

#endif