/*
 * Copyright 2008-2014 Arsen Chaloyan
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 * $Id: mrcp_generic_header.h 2136 2014-07-04 06:33:36Z achaloyan@gmail.com $
 */

#ifndef MRCP_GENERIC_HEADER_H
#define MRCP_GENERIC_HEADER_H

/**
 * @file mrcp_generic_header.h
 * @brief MRCP Generic Header
 */ 

#include "mrcp_types.h"
#include "mrcp_header_accessor.h"

APT_BEGIN_EXTERN_C

/** Enumeration of MRCP generic header fields */
typedef enum {
	GENERIC_HEADER_ACTIVE_REQUEST_ID_LIST,
	GENERIC_HEADER_PROXY_SYNC_ID,
	GENERIC_HEADER_ACCEPT_CHARSET,
	GENERIC_HEADER_CONTENT_TYPE,
	GENERIC_HEADER_CONTENT_ID,
	GENERIC_HEADER_CONTENT_BASE,
	GENERIC_HEADER_CONTENT_ENCODING,
	GENERIC_HEADER_CONTENT_LOCATION,
	GENERIC_HEADER_CONTENT_LENGTH,
	GENERIC_HEADER_CACHE_CONTROL,
	GENERIC_HEADER_LOGGING_TAG,
	GENERIC_HEADER_VENDOR_SPECIFIC_PARAMS,
	
	/** Additional header fields for MRCP v2 */
	GENERIC_HEADER_ACCEPT,
	GENERIC_HEADER_FETCH_TIMEOUT,
	GENERIC_HEADER_SET_COOKIE,
	GENERIC_HEADER_SET_COOKIE2,

	GENERIC_HEADER_COUNT
} mrcp_generic_header_id;

/** MRCP request identifiers list declaration */
typedef struct mrcp_request_id_list_t mrcp_request_id_list_t;
/** MRCP vendor specific parameter list of pairs */
typedef struct mrcp_vendor_specific_params_list_t mrcp_vendor_specific_params_list_t;
/** MRCP generic header declaration */
typedef struct mrcp_generic_header_t mrcp_generic_header_t;

/** Max number of request ids in active request id list */
#define MAX_ACTIVE_REQUEST_ID_COUNT 5
/** List (array) of MRCP request identifiers */
struct mrcp_request_id_list_t {
	/** Array of request identifiers */
	mrcp_request_id ids[MAX_ACTIVE_REQUEST_ID_COUNT];
	/** Number of request identifiers */
	apr_size_t          count;
};


/** MRCP generic header */
struct mrcp_generic_header_t {
	/** Indicates the list of request-ids to which it should apply */
	mrcp_request_id_list_t active_request_id_list;
	/** Helps the resource receiving the event, proxied by the client, 
	to decide if this event has been processed through a direct interaction of the resources */
	apt_str_t              proxy_sync_id;
	/** Specifies the acceptable character set for entities returned in the response or events associated with this request */
	apt_str_t              accept_charset;
	/** Restricted to speech markup, grammar, recognition results, etc. */
	apt_str_t              content_type;
	/** Contains an ID or name for the content, by which it can be referred to */
	apt_str_t              content_id;
	/** May be used to specify the base URI for resolving relative URLs within the entity */
	apt_str_t              content_base;
	/** Indicates what additional content coding has been applied to the entity-body */
	apt_str_t              content_encoding;
	/** Statement of the location of the resource corresponding to this particular entity at the time of the request */
	apt_str_t              content_location;
	/** Contains the length of the content of the message body */
	size_t                 content_length;
	/** Defines the default caching algorithms on the media server for the session or request */
	apt_str_t              cache_control;
	/** Sets the logging tag for logs generated by the media server */
	apt_str_t              logging_tag;
	/** Specifies the vendor specific parameters used by the media server */
	apt_pair_arr_t        *vendor_specific_params;

	/** Additional header fields for MRCP v2 */
	/** Specifies the acceptable media types set for entities returned in the response or events associated with this request */
	apt_str_t              accept;
	/** Defines the timeout for content that the server may need to fetch over the network */
	apr_size_t             fetch_timeout;
	/** Enables to synchronize the cookie store of MRCP v2 client and server */
	apt_str_t              set_cookie;
	/** Enables to synchronize the cookie store of MRCP v2 client and server */
	apt_str_t              set_cookie2;
};

/** Get generic header vtable */
MRCP_DECLARE(const mrcp_header_vtable_t*) mrcp_generic_header_vtable_get(mrcp_version_e version);


/** Append active request id list */
MRCP_DECLARE(apt_bool_t) active_request_id_list_append(mrcp_generic_header_t *generic_header, mrcp_request_id request_id);
/** Find request id in active request id list */
MRCP_DECLARE(apt_bool_t) active_request_id_list_find(const mrcp_generic_header_t *generic_header, mrcp_request_id request_id);


APT_END_EXTERN_C

#endif /* MRCP_GENERIC_HEADER_H */
