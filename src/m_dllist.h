// DR. ROBOTNIK'S RING RACERS
//-----------------------------------------------------------------------------
// Copyright (C) 2025 by Kart Krew.
// Copyright (C) 2020 by Sonic Team Junior.
// Copyright (C) 2005 by James Haley.
//
// This program is free software distributed under the
// terms of the GNU General Public License, version 2.
// See the 'LICENSE' file for more details.
//-----------------------------------------------------------------------------
/// \file  m_dllist.h
/// \brief Generalized Double-linked List Routines

// haleyjd 08/05/05: This is Lee Killough's smart double-linked list
// implementation with pointer-to-pointer prev links, generalized to
// be able to work with any structure. This type of double-linked list
// can only be traversed from head to tail, but it treats all nodes
// uniformly even without the use of a dummy head node, and thus it is
// very efficient. These routines are inlined for maximum speed.
//
// Just put an mdllistitem_t as the first item in a structure and you
// can then cast a pointer to that structure to mdllistitem_t * and
// pass it to these routines. You are responsible for defining the
// pointer used as the head of the list.

#ifndef M_DLLIST_H__
#define M_DLLIST_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _MSC_VER
#pragma warning(disable : 4706)
#endif

struct mdllistitem_t
{
	mdllistitem_t *next;
	mdllistitem_t **prev;
};

FUNCINLINE static ATTRINLINE void M_DLListInsert(mdllistitem_t *item, mdllistitem_t **head)
{
	mdllistitem_t *next = *head;

	if ((item->next = next))
		next->prev = &item->next;
	item->prev = head;
	*head = item;
}

FUNCINLINE static ATTRINLINE void M_DLListRemove(mdllistitem_t *item)
{
	mdllistitem_t **prev = item->prev;
	mdllistitem_t *next  = item->next;

	if ((*prev = next))
		next->prev = prev;
}

#ifdef __cplusplus
} // extern "C"
#endif

#endif

// EOF
