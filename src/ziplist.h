/*
 * Copyright (c) 2009-2012, Pieter Noordhuis <pcnoordhuis at gmail dot com>
 * Copyright (c) 2009-2012, Salvatore Sanfilippo <antirez at gmail dot com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of Redis nor the names of its contributors may be used
 *     to endorse or promote products derived from this software without
 *     specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#define ZIPLIST_HEAD 0
#define ZIPLIST_TAIL 1

/* 构建全新的ziplist */
unsigned char *ziplistNew(void);
/* 从指定方向插入数据 */
unsigned char *ziplistPush(unsigned char *zl, unsigned char *s, unsigned int slen, int where);
/* 返回指定的Entry([1,2,3,4,...-4,-3,-2,-1]) */
unsigned char *ziplistIndex(unsigned char *zl, int index);
/* 返回next  .Entry */
unsigned char *ziplistNext(unsigned char *zl, unsigned char *p);
/* 返回prev.Entry */
unsigned char *ziplistPrev(unsigned char *zl, unsigned char *p);
/* 根据编码STRING/INT来提取指定的Entry的值p */
unsigned int ziplistGet(unsigned char *p, unsigned char **sval, unsigned int *slen, long long *lval);
/* 在指定位置插入数据 */
unsigned char *ziplistInsert(unsigned char *zl, unsigned char *p, unsigned char *s, unsigned int slen);
/* 删除指定位置的Entry */
unsigned char *ziplistDelete(unsigned char *zl, unsigned char **p);
/*　从指定位置开始，删除N个Entry            */
unsigned char *ziplistDeleteRange(unsigned char *zl, unsigned int index, unsigned int num);
/*　对比　*/
unsigned int ziplistCompare(unsigned char *p, unsigned char *s, unsigned int slen);
/* 从p开始查找指定的Entry，若每次对比失败，则间隔skip个元素后再尝试下查找 */
unsigned char *ziplistFind(unsigned char *p, unsigned char *vstr, unsigned int vlen, unsigned int skip);
/* ziplist的元素总个数 */
unsigned int ziplistLen(unsigned char *zl);
/* ziplist占用的总BYTE数 */
size_t ziplistBlobLen(unsigned char *zl);
