// db_compat.hpp
#pragma once
#include <pqxx/pqxx>

template <typename... Args>
pqxx::result exec_p(pqxx::transaction_base& txn, const char* query, Args&&... args) {
#if PQXX_VERSION_MAJOR >= 8
    return txn.exec(query, pqxx::params{std::forward<Args>(args)...});
#else
    return txn.exec_params(query, std::forward<Args>(args)...);
#endif
}