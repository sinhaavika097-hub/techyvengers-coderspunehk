-- KNOWBRIDGE AI SQLite Schema
-- Compliant with CodersInPune Hackathon Specifications (Section 8: Proposed Data Model)

CREATE TABLE IF NOT EXISTS Projects (
    project_id TEXT PRIMARY KEY,
    name TEXT NOT NULL,
    objective TEXT,
    departing_lead TEXT,
    incoming_lead TEXT,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE IF NOT EXISTS Sources (
    source_id TEXT PRIMARY KEY,
    project_id TEXT NOT NULL,
    filename TEXT NOT NULL,
    format TEXT NOT NULL,
    file_size INTEGER DEFAULT 0,
    uploaded_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    status TEXT DEFAULT 'processed',
    FOREIGN KEY(project_id) REFERENCES Projects(project_id) ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS SourceChunks (
    chunk_id TEXT PRIMARY KEY,
    source_id TEXT NOT NULL,
    text TEXT NOT NULL,
    row_or_line_ref TEXT,
    FOREIGN KEY(source_id) REFERENCES Sources(source_id) ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS KnowledgeItems (
    item_id TEXT PRIMARY KEY,
    project_id TEXT NOT NULL,
    type TEXT NOT NULL, -- 'decision', 'task', 'ownership', 'blocker', 'risk', 'next_action'
    title TEXT NOT NULL,
    description TEXT,
    status TEXT DEFAULT 'draft', -- 'draft', 'approved', 'rejected'
    confidence REAL DEFAULT 0.90,
    owner TEXT DEFAULT 'Unconfirmed',
    priority TEXT DEFAULT 'Medium', -- 'Critical', 'High', 'Medium', 'Low'
    rationale TEXT,
    component TEXT,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY(project_id) REFERENCES Projects(project_id) ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS EvidenceLinks (
    link_id TEXT PRIMARY KEY,
    item_id TEXT NOT NULL,
    chunk_id TEXT,
    source_filename TEXT NOT NULL,
    row_or_line_ref TEXT,
    excerpt TEXT NOT NULL,
    FOREIGN KEY(item_id) REFERENCES KnowledgeItems(item_id) ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS PeopleRoles (
    person_id TEXT PRIMARY KEY,
    project_id TEXT NOT NULL,
    display_name_or_role TEXT NOT NULL,
    email TEXT,
    is_backup INTEGER DEFAULT 0,
    component TEXT,
    FOREIGN KEY(project_id) REFERENCES Projects(project_id) ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS Relationships (
    relation_id TEXT PRIMARY KEY,
    project_id TEXT NOT NULL,
    from_id TEXT NOT NULL,
    to_id TEXT NOT NULL,
    relation_type TEXT NOT NULL, -- 'depends_on', 'owns', 'impacts', 'blocks'
    FOREIGN KEY(project_id) REFERENCES Projects(project_id) ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS ReviewActions (
    review_id TEXT PRIMARY KEY,
    item_id TEXT NOT NULL,
    reviewer TEXT NOT NULL,
    decision TEXT NOT NULL, -- 'approved', 'rejected', 'modified'
    timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    notes TEXT,
    FOREIGN KEY(item_id) REFERENCES KnowledgeItems(item_id) ON DELETE CASCADE
);

CREATE INDEX IF NOT EXISTS idx_chunks_source ON SourceChunks(source_id);
CREATE INDEX IF NOT EXISTS idx_items_project ON KnowledgeItems(project_id);
CREATE INDEX IF NOT EXISTS idx_items_type ON KnowledgeItems(type);
CREATE INDEX IF NOT EXISTS idx_evidence_item ON EvidenceLinks(item_id);
CREATE INDEX IF NOT EXISTS idx_review_item ON ReviewActions(item_id);
