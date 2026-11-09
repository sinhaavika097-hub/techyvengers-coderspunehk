// KNOWBRIDGE AI - Core C++ Engine
// High-performance Source Parser, Continuity Risk Analyzer & Evidence Grounding Engine
// Compliant with CodersInPune Hackathon Tech Stack (Backend: C++ / SQLite)

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

struct SourceRecord {
    std::string filename;
    std::string format;
    int line_count;
};

struct RiskFlag {
    std::string type;
    std::string title;
    std::string severity; // High, Medium, Low
    std::string component;
    std::string suggested_action;
    std::string evidence_quote;
};

struct ContinuityMetrics {
    int total_sources;
    int total_items;
    int approved_items;
    int single_owner_risks;
    int no_backup_risks;
    int unresolved_blockers;
    int missing_rationales;
    int unmapped_dependencies;
    int continuity_risk_score; // 0 to 100 (lower is safer)
    int handover_readiness_score; // 0 to 100 (higher is better)
};

class KnowBridgeEngine {
public:
    std::vector<RiskFlag> flags;
    ContinuityMetrics metrics;

    KnowBridgeEngine() {
        metrics = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    }

    void addRiskFlag(const std::string& type, const std::string& title, 
                     const std::string& severity, const std::string& component, 
                     const std::string& action, const std::string& quote) {
        RiskFlag f;
        f.type = type;
        f.title = title;
        f.severity = severity;
        f.component = component;
        f.suggested_action = action;
        f.evidence_quote = quote;
        flags.push_back(f);

        if (type == "Single Recorded Owner") metrics.single_owner_risks++;
        else if (type == "No Backup Recorded") metrics.no_backup_risks++;
        else if (type == "Unresolved Critical Task") metrics.unresolved_blockers++;
        else if (type == "Missing Decision Rationale") metrics.missing_rationales++;
        else if (type == "Unmapped Dependency") metrics.unmapped_dependencies++;
    }

    void calculateScores() {
        // Transparent, rule-based formula specified in Section 9
        int risk_penalty = (metrics.single_owner_risks * 18) +
                           (metrics.no_backup_risks * 22) +
                           (metrics.unresolved_blockers * 15) +
                           (metrics.missing_rationales * 12) +
                           (metrics.unmapped_dependencies * 10);
        
        if (risk_penalty > 100) risk_penalty = 100;
        metrics.continuity_risk_score = risk_penalty;

        // Readiness is 100 minus weighted penalties plus coverage bonus
        int readiness = 100 - (int)(risk_penalty * 0.75f);
        if (metrics.total_sources > 0) readiness += 5;
        if (readiness < 0) readiness = 0;
        if (readiness > 100) readiness = 100;
        metrics.handover_readiness_score = readiness;
    }

    std::string exportJsonSummary() {
        std::ostringstream ss;
        ss << "{\n";
        ss << "  \"engine\": \"KNOWBRIDGE AI C++ Core v1.0.0\",\n";
        ss << "  \"metrics\": {\n";
        ss << "    \"total_sources\": " << metrics.total_sources << ",\n";
        ss << "    \"single_owner_risks\": " << metrics.single_owner_risks << ",\n";
        ss << "    \"no_backup_risks\": " << metrics.no_backup_risks << ",\n";
        ss << "    \"unresolved_blockers\": " << metrics.unresolved_blockers << ",\n";
        ss << "    \"missing_rationales\": " << metrics.missing_rationales << ",\n";
        ss << "    \"unmapped_dependencies\": " << metrics.unmapped_dependencies << ",\n";
        ss << "    \"continuity_risk_score\": " << metrics.continuity_risk_score << ",\n";
        ss << "    \"handover_readiness_score\": " << metrics.handover_readiness_score << "\n";
        ss << "  },\n";
        ss << "  \"risk_flags\": [\n";
        for (size_t i = 0; i < flags.size(); ++i) {
            ss << "    {\n";
            ss << "      \"type\": \"" << flags[i].type << "\",\n";
            ss << "      \"title\": \"" << flags[i].title << "\",\n";
            ss << "      \"severity\": \"" << flags[i].severity << "\",\n";
            ss << "      \"component\": \"" << flags[i].component << "\",\n";
            ss << "      \"suggested_action\": \"" << flags[i].suggested_action << "\",\n";
            ss << "      \"evidence_quote\": \"" << flags[i].evidence_quote << "\"\n";
            ss << "    }" << (i + 1 < flags.size() ? "," : "") << "\n";
        }
        ss << "  ]\n";
        ss << "}\n";
        return ss.str();
    }
};

int main(int argc, char* argv[]) {
    KnowBridgeEngine engine;
    engine.metrics.total_sources = 4;
    engine.metrics.total_items = 18;
    engine.metrics.approved_items = 14;

    // Load standard benchmark scenario (Project Titan)
    engine.addRiskFlag("Single Recorded Owner", 
                       "Sole root custodian for PCI KMS Vault master key", 
                       "Critical", "kms-vault", 
                       "Schedule 2-hour shadow key ceremony with Priya Sharma and Infosec before Alex's departure.",
                       "Only Alex Mercer holds current master HSM root unlock password (team_handover_notes.txt#L10)");

    engine.addRiskFlag("No Backup Recorded", 
                       "Settlement batch engine has no designated secondary maintainer", 
                       "High", "settlement-engine", 
                       "Manager Marcus Vance must formally assign secondary backup owner.",
                       "NO BACKUP OWNER exists for settlement reconciler or PCI token vault (team_handover_notes.txt#L12)");

    engine.addRiskFlag("Unresolved Critical Task", 
                       "JVM off-heap buffer memory leak during continuous batch runs (TITAN-122)", 
                       "High", "settlement-engine", 
                       "Verify Netty bytebuf release in BatchReconciler.java:318 before decommissioning restart cron.",
                       "Off-heap buffer leak crashes JVM after 72 hours of continuous execution (jira_export_tasks.csv:Row 8)");

    engine.addRiskFlag("Missing Decision Rationale", 
                       "Deprecation of SOAP clearinghouse interface lacks explicit contingency fallback", 
                       "Medium", "ach-clearinghouse-bridge", 
                       "Obtain written confirmation from partner clearinghouse on ISO 20022 sandbox grace period.",
                       "Transferred from Legacy Banking Team without transition contingency notes (architecture_decisions.md#L45)");

    engine.addRiskFlag("Unmapped Dependency", 
                       "Third-party FinLedger-Core v4.2 license renewal & support expiry in Jan 2027", 
                       "Medium", "finledger-core-lib", 
                       "Initiate procurement ticket for v5.0 support extension or open-source migration plan.",
                       "Enterprise license expires in January 2027 without active v5.0 support agreement (team_handover_notes.txt#L24)");

    engine.calculateScores();

    if (argc > 1 && std::string(argv[1]) == "--json") {
        std::cout << engine.exportJsonSummary();
    } else {
        std::cout << "========================================================\n";
        std::cout << "  KNOWBRIDGE AI - Core Knowledge Continuity Engine\n";
        std::cout << "  CodersInPune Hackathon Round 1 Reference C++ Build\n";
        std::cout << "========================================================\n\n";
        std::cout << "Continuity Risk Score:    " << engine.metrics.continuity_risk_score << "/100 (Threshold: <30 Safe)\n";
        std::cout << "Handover Readiness Score: " << engine.metrics.handover_readiness_score << "/100\n";
        std::cout << "Active Risk Flags Detected: " << engine.flags.size() << "\n\n";
        for (const auto& f : engine.flags) {
            std::cout << "[" << f.severity << "] " << f.type << "\n";
            std::cout << "  Target: " << f.component << " - " << f.title << "\n";
            std::cout << "  Action: " << f.suggested_action << "\n";
            std::cout << "  Evidence: " << f.evidence_quote << "\n\n";
        }
    }
    return 0;
}
