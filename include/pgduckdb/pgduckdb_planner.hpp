#pragma once

#include "duckdb.hpp"

extern "C" {
#include "postgres.h"
#include "optimizer/planner.h"
}

#include "pgduckdb/pgduckdb_duckdb.hpp"

extern bool duckdb_explain_analyze;

PlannedStmt *DuckdbPlanNode(Query *parse, const char *query_string, int cursor_options, ParamListInfo bound_params,
                            bool throw_error);
duckdb::unique_ptr<duckdb::PreparedStatement> DuckdbPrepare(const Query *query);
