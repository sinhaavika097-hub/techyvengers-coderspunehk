# 🏆 CodersInPune Hackathon — Round 2 Official Submission
**Team Name:** TECHY'VENGERS  
**Team Leader:** Kamal Lochan Mishra  
**Project Title:** KNOWBRIDGE AI — Source-Grounded Knowledge Continuity & Brand Governance Platform  
**Target Category:** Brand & Project Knowledge Governance Platform  
**Status:** Round 2 Working Build (Functional MVP)  

---

## 1. Working Project Link
- **Live Demo Link (No Sign-in Required, Incognito Verified):**  
  `https://kamal-lochan-mishra.github.io/knowbridge-ai/`  
  *(Alternative Direct Link: Open `index.html` in any browser — zero setup, zero authentication, 100% functional offline & online).*

> **Verification Note for Judges:**  
> This project has been tested in Chrome & Edge **Incognito / Private Window**. It loads immediately with zero login prompts, zero API keys required from the reviewer, and includes **1-Click Pre-Loaded Test Scenarios** on the top bar.

---

## 2. Source-Code Repository Link
- **GitHub Repository:**  
  `https://github.com/Kamal-Lochan-Mishra/knowbridge-ai`  
  *(Repository contains `index.html`, `server.py`, `schema.sql`, `knowbridge_core.cpp`, `sample_data/`, and `README.md`).*

---

## 3. List of Completed Features (Round 2 Working Build)

1. **Central Brand & Knowledge Governance Workflow:**
   - Raw draft content (handover memos, marketing releases, ADRs, compliance docs) is ingested and parsed in real time.
   - Tested automatically against 6 authorized project guidelines, Architecture Decision Records (ADRs), and compliance mandates.
2. **Explainable Issue Detection & Evidence Grounding:**
   - Detects critical policy breaches (e.g. reverting to standalone Redis locking against ADR-001, single-owner KMS root key bottleneck against PCI-DSS SEC-002, unverified 100% SLA claims against BRD-005).
   - Every flagged issue cites the **exact source document**, line/row number, and supporting quote.
3. **Human-in-the-Loop Governance (Final Decision Maker):**
   - Reviewer controls allow human managers (Kamal Lochan Mishra / Marcus Vance) to **Approve (✓)**, **Reject (✗)**, or **Override & Correct (✎)** claims with an audit trail.
4. **Mission Control & Explainable Risk Scoring:**
   - Real-time **Handover & Governance Readiness Gauge (78/100)** with transparent mathematical rule weights (not black-box numbers).
   - Active risk breakdown highlighting single points of failure and fragile workarounds.
5. **Interactive Knowledge & Ownership Topology Map:**
   - HTML5 Canvas dynamic relationship graph mapping **People (Purple)** ➔ **Services/Modules (Dark Blue)** ➔ **Decisions (Green)** ➔ **Risks/Blockers (Red)** with draggable nodes and visual pulsing risk boundary rings.
6. **Grounded Q&A Assistant with Strict Anti-Hallucination Guardrails:**
   - "Ask the Rulebook" console strictly grounded in authorized project sources with exact citation chips.
   - Built-in guardrail automatically blocks and explains why sensitive speculation (e.g. root passwords, employee resignation predictions) is strictly prohibited.
7. **3 Pre-Loaded 1-Click Jury Scenarios:**
   - Scenario 1: Critical Compliance Breach (Redis lock revert, KMS root bottleneck, 100% SLA exaggeration).
   - Scenario 2: High-Risk Lead Transition (Alex Mercer to Priya Sharma with shadow ceremony).
   - Scenario 3: 100% Certified Clean Brand Release.

---

## 4. Technology & Implementation Details

- **Frontend Presentation Layer:**  
  - Semantic HTML5 & modern CSS3 utilizing a high-contrast dark theme with glowing accents in **Dark Blue (`#070b14`), Purple (`#8b5cf6`), Green (`#10b981`), and Red (`#ef4444`)**.
  - Interactive HTML5 Canvas vector engine for real-time physics-based draggable node-link topology rendering.
  - Responsive CSS Grid and Flexbox layouts; typography powered by `Inter` and `JetBrains Mono`.
- **Application & Grounding Engine:**  
  - Client-side deterministic heuristic rule engine evaluating draft text against tokenized rule dictionaries and regex constraints.
  - Python 3 REST API server (`server.py`) handling `/api/health`, `/api/knowledge-items`, `/api/risk-indicators`, `/api/qa/ask`.
- **Data Persistence:**  
  - SQLite 3 database (`knowbridge.db` / `schema.sql`) with a normalized 8-table relational architecture: `Projects`, `Sources`, `SourceChunks`, `KnowledgeItems`, `EvidenceLinks`, `PeopleRoles`, `Relationships`, `ReviewActions`.
- **Reference C++ Core Module:**  
  - High-performance C++ continuity risk engine and tokenizer (`knowbridge_core.cpp`) compiling under MinGW `g++`.

---

## 5. Explanation of Changes Made to the Original Plan

In Round 1, our proposal focused primarily on post-hoc project handover documentation. However, in direct alignment with the official Round 2 judging brief—which requires an end-to-end governance workflow where *"content goes in, it is checked against approved guidelines, issues are clearly explained, and a human makes the final decision"*—we made three strategic enhancements:

1. **Front-Loaded Central Audit Console:** Promoted the live draft content editor to Tab #1 with instant real-time audit feedback, allowing judges to test any text in seconds.
2. **1-Click Jury Scenario Switcher:** Added preset test buttons on the top bar (Critical Breach vs. Clean Release) so that evaluators in Incognito mode can immediately trigger the entire validation engine without needing to draft mock documents.
3. **Advanced Interactive Knowledge Graph:** Delivered the interactive Canvas topology map earlier than scheduled in the Round 1 roadmap to make single-owner bottlenecks visually undeniable.

---

## 6. Three Major Improvements for Round 3 (Meaningful / Non-Cosmetic)

1. **Enterprise Vector Embeddings & Hybrid Semantic Contradiction Detector:**  
   - Integrate an on-device local vector store (SQLite-vec / Transformers.js / Chroma) to detect subtle semantic contradictions and brand drift even when exact keywords differ (e.g. recognizing *"we use unencrypted in-transit pipes"* violates *"all transport requires TLS 1.2+"*).
2. **Automated CI/CD & CMS Pre-Publish Blocking Webhooks:**  
   - Build GitHub Action and Headless CMS webhooks (for Strapi, WordPress, and GitHub PRs) that automatically block pull request merges or marketing publication if critical unapproved governance breaches exist in the submission queue.
3. **Multi-Party Cryptographic Sign-Off & Merkle Audit Trail:**  
   - Introduce asymmetric cryptographic key signing (Ed25519) for sensitive ownership transfers (e.g. requiring dual digital signatures from both the departing architect and engineering director) backed by a tamper-evident Merkle hash chain.
