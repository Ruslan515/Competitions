create table public.scsdata (
  id uuid primary key not null default uuid_generate_v4(),
  ats timestamp(0) without time zone not null,
  uts timestamp(0) without time zone,
  layer character varying(255) not null,
  code character varying(255) not null,
  jrefdata jsonb,
  tid character varying(255),
  runique uuid not null default uuid_generate_v4(),
  jdata jsonb,
  jstatus jsonb,
  vearsion integer not null default 0,
  jmeta jsonb,
  iid integer not null default nextval('scsdata_iid_seq'::regclass),
  dts timestamp(0) without time zone default NULL::timestamp without time zone
);