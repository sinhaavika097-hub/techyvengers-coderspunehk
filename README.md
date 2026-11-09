# 🌉 KNOWBRIDGE AI — Project Knowledge Continuity & Handover Platform

> **CodersInPune Hackathon — Round 1 Proposal & Working MVP**  
> *"Never Lose Knowledge. Never Restart Work."*  
> A source-grounded project knowledge continuity and handover workspace built with evidence-first extraction, transparent risk scoring, interactive dependency mapping, and human-in-the-loop verification.

---

## 🚀 Live Demo Quickstart

### Option 1: Live Local Web Server (Currently Running & Ready!)
The backend server and SQLite database are already active and serving on:
👉 **[http://localhost:8080](http://localhost:8080)** (or **[http://127.0.0.1:8080](http://127.0.0.1:8080)**)

### Option 2: Zero-Dependency Double-Click Launch
Open the self-contained frontend directly in Chrome, Edge, Safari, or Firefox without any server:
👉 Double-click [`index.html`](file:///C:/Users/Kamal%20Lochan%20Mishra/.gemini/antigravity/scratch/knowbridge-ai/index.html) in Windows File Explorer.  
*(Dual-mode architecture: seamlessly uses browser memory and local heuristics if opened as a standalone static file).*

### Option 3: Start Server from Terminal
```powershell
cd "C:\Users\Kamal Lochan Mishra\.gemini\antigravity\scratch\knowbridge-ai"
python server.py 8080
```

---

## 🎯 4-Minute Hackathon Jury Demo Script

Judges evaluate proposals based on **Problem Understanding**, **Solution Quality**, **Technical Feasibility**, and **Originality**. Use the **Top Jury Demo Bar** to deliver a winning demonstration:

### 1. 📊 Mission Control & Explainable Risk Scoring (Minute 1)
- **Handover Readiness Score (84/100)**: Visualized via radial SVG progress gauge with explicit rule weights (approved decisions, coverage ratio, open blocker penalties).
- **Explainable Continuity Risk Flags**: Rather than black-box AI predictions, the engine detects 5 transparent operational risks:
  - 🚩 **Single Recorded Owner**: `kms-vault` relies exclusively on departing architect Alex Mercer.
  - 🚩 **No Backup Recorded**: `settlement-engine` has null backup maintainer in `service_dependencies.json`.
  - 🚩 **Unresolved Critical Task**: TITAN-122 JVM off-heap buffer memory leak with fragile 48-hour pod reboot cronjob.
  - 🚩 **Missing Decision Rationale**: Deprecation of SOAP clearinghouse interface lacks explicit contingency fallback.
  - 🚩 **Unmapped Dependency**: Third-party `FinLedger-Core v4.2` library license expiring in January 2027.
- **Actionable Remediation**: Every flag specifies the exact suggested manager action and links to the supporting source excerpt.

### 2. 📋 Manager Review Queue & Evidence Inspector (Minute 2)
- **Key Safeguard**: *"AI output remains a DRAFT until a human verifies it."*
- Click **"📋 Manager Review Queue"** tab to filter across 6 structured categories:
  - **Decisions** (ADRs with strict rationale, e.g. Hazelcast IMDG for distributed locking)
  - **Tasks** (Open, Blocked, and Completed tickets with priority levels)
  - **Blockers** (Fragile workarounds and memory leaks)
  - **Risks** (Single points of failure and vendor expirations)
  - **Ownership** (Primary custodians and unconfirmed roles)
  - **Next Actions** (Step-by-step roadmap for incoming engineer Priya Sharma)
- **Traceable Grounding**: Click any **"🔍 Evidence: source_file.md"** chip to open the **Evidence Inspector Drawer**, revealing the exact highlighted quote, row/line number, and manager audit trail.
- **Human Approval**: Click **"✓ Approve"**, **"✎ Edit"**, or **"✗ Reject"** to update status and persist changes to the SQLite database.

### 3. 🕸️ Interactive Knowledge Dependency Map (Minute 3)
- Switch to the **"🕸️ Dependency Map"** tab.
- An interactive SVG/Canvas graph connects:
  - 👤 **People & Roles**: Alex Mercer (Departing Lead), Priya Sharma (Incoming Lead), Sarah Chen, Marcus Vance
  - 📦 **Services & Modules**: `kms-vault`, `settlement-engine`, `ledger-engine`, `payment-gateway`, `event-bus`
  - 💡 **Architectural Decisions**: Hazelcast lock, mandatory idempotency keys
  - ⚡ **Critical Blockers**: TITAN-122 JVM memory leak
- **Visual Risk Rings**: Risky single-owner modules pulse with dashed red/amber boundary rings. Drag and reposition nodes in real time!

### 4. 🤖 Grounded Q&A Assistant & Anti-Hallucination Safeguard (Minute 4)
- Navigate to the **"🤖 Grounded Q&A Assistant"** tab.
- Click preset query: *"Why did we replace Redis with Hazelcast for locking?"*
  - Instant response citing `architecture_decisions.md (Line 8-15)` and the split-brain Black Friday test failure.
- Click safeguard test query: *"What is the root AWS production secret password?"* or *"Predict employee resignation"*.
  - **Safeguard Activated**: Explains that out-of-scope or sensitive speculation is strictly blocked by KNOWBRIDGE AI guardrails.

### 5. 📑 Handover Report Dossier & Print View
- Navigate to **"📑 Handover Report Dossier"** to view the auto-generated executive transition package.
- Click **"📥 Export Handover (.md)"** to download the clean Markdown dossier.
- Click **"💾 Export JSON Package"** to download the complete audit trail.
- Click **"🖨️ Print Dossier"** for a clean, paginated PDF print layout.

---

## 🏗️ Technical Architecture & Compliance

| Layer | Implementation | Hackathon Specification Match |
|---|---|---|
| **Presentation** | Responsive HTML5, CSS3, JavaScript (Canvas & SVG Graph) | Responsive workspace, upload flow, dashboard, evidence display, review controls, report preview |
| **API / Application** | Python 3 HTTP Server (`server.py`) | REST API routes, request validation, project/source operations, grounding engine |
| **Persistence** | SQLite 3 (`knowbridge.db`) | Projects, Sources, SourceChunks, KnowledgeItems, EvidenceLinks, PeopleRoles, Relationships, ReviewActions |
| **C++ Core Engine** | `knowbridge_core.cpp` | C++ knowledge parsing, continuity risk calculation, and JSON export |
| **Supported Formats** | TXT, Markdown (.md), CSV, JSON | Validated in `sample_data/` directory |

---

## 📁 Repository & File Directory

```
knowbridge-ai/
├── index.html                  # Complete responsive frontend web application
├── server.py                    # Python HTTP server & REST API
├── schema.sql                   # SQLite schema matching Proposal Section 8
├── knowbridge.db                # Live SQLite 3 database
├── knowbridge_core.cpp          # Reference C++ parsing & risk scoring engine
├── sample_data/                 # Synthetic benchmark dataset
│   ├── architecture_decisions.md  # 4 Architecture Decision Records (ADRs)
│   ├── jira_export_tasks.csv       # 8 Jira work items & status export
│   ├── team_handover_notes.txt     # Raw memorandum from departing lead
│   └── service_dependencies.json   # Microservice ownership & SLA graph
└── README.md                    # This documentation and demo guide
```

---

## 👥 Hackathon Team Information (CodersInPune Round 1)

- **Platform**: KNOWBRIDGE AI
- **Tagline**: Never Lose Knowledge. Never Restart Work.
- **Focus**: Source-grounded project continuity and verifiable handovers.
