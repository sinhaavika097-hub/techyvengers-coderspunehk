# Project Titan: Architecture Decision Records (ADRs)
**Workspace**: Core Payments & Ledger Gateway Migration  
**Author**: Alex Mercer (Staff Systems Architect)  
**Last Updated**: October 28, 2026  
**Status**: Active Production Reference  

---

### ADR-001: Hazelcast In-Memory Grid for Distributed Locking
- **Date**: 2026-08-14
- **Decision**: Replace Redis standalone cluster with Hazelcast distributed IMDG for mutual exclusion locks on ledger write transactions.
- **Rationale**: During peak black Friday load tests, Redis sentinel failover experienced split-brain race conditions that allowed double-commit window of 18ms. Hazelcast provides strict CP (Consistency/Partition-tolerance) mode under Raft consensus, eliminating duplicate ledger settlements.
- **Components Impacted**: `ledger-engine`, `payment-gateway`, `reconciliation-worker`
- **Owner**: Alex Mercer
- **Review Status**: Approved by Architecture Board

---

### ADR-002: Mandatory Idempotency Keys on All POST /v2/charge Routes
- **Date**: 2026-09-02
- **Decision**: Require client-supplied UUIDv4 `X-Idempotency-Key` header with 24-hour TTL caching in memory.
- **Rationale**: Merchant mobile SDK drops caused repeated retry requests during spotty 4G cell tower handoffs, creating duplicate ledger reservations.
- **Components Impacted**: `api-gateway`, `ingress-proxy`, `checkout-service`
- **Owner**: Sarah Chen
- **Review Status**: Approved by Marcus Vance

---

### ADR-003: Weekly Partitioning Strategy for PostgreSQL `ledger_transactions`
- **Date**: 2026-09-21
- **Decision**: Subdivide database tables by week rather than by calendar month.
- **Rationale**: High volume (>12M transactions/day) caused index scans on monthly tables to exceed 580ms latency threshold. Weekly partitions keep B-Tree indexes fully inside memory cache, reducing P99 latency to 14ms.
- **Components Impacted**: `db-cluster`, `reporting-cron`
- **Owner**: Alex Mercer
- **Review Status**: Approved

---

### ADR-004: Deprecation of Legacy SOAP ACH Batch Clearing
- **Date**: 2026-10-15
- **Decision**: Terminate SOAP XML endpoint and migrate strictly to ISO 20022 RESTful JSON payloads.
- **Rationale**: Federal clearinghouse banking partner mandated ISO 20022 sunset date of November 30, 2026.
- **Components Impacted**: `ach-clearinghouse-bridge`
- **Owner**: Unconfirmed (Transferred from Legacy Banking Team)
- **Review Status**: Pending Final Infosec Signoff
