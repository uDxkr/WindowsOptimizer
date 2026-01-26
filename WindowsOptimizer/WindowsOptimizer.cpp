#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>
using namespace std;
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define PURPLE  "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BBLACK   "\033[90m"
#define BRED     "\033[91m"
#define BGREEN   "\033[92m"
#define BYELLOW  "\033[93m"
#define BBLUE    "\033[94m"
#define BPURPLE  "\033[95m"
#define BCYAN    "\033[96m"
#define BWHITE   "\033[97m"
#define BOLD        "\033[1m"
#define DIM         "\033[2m"
#define ITALIC      "\033[3m"
#define UNDERLINE   "\033[4m"

void sleep(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}
void clearScreen() {
    system("cls");
}
void pause() {
    system("pause");
}
string getUsername() {
    char user[256];
    DWORD size = 256;
    GetUserNameA(user, &size);
    return string(user);
}
string getDate() {
    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%d/%m/%Y", &ltm);
    return string(buffer);
}
bool isAdmin() {
    BOOL admin = FALSE;
    PSID adminGroup;
    SID_IDENTIFIER_AUTHORITY ntAuthority = SECURITY_NT_AUTHORITY;
    AllocateAndInitializeSid(&ntAuthority, 2, SECURITY_BUILTIN_DOMAIN_RID, DOMAIN_ALIAS_RID_ADMINS, 0, 0, 0, 0, 0, 0, &adminGroup);
    CheckTokenMembership(NULL, adminGroup, &admin);
    FreeSid(adminGroup);
    return admin;
}

void menu() {
    system(("title Cleaner Windows 11 PRO - " + getUsername()).c_str());
    clearScreen();
    cout << CYAN "=============================================================================\n";
    cout << BOLD GREEN "                    CLEANER & DEBLOATER v2.0\n" RESET;
    cout << WHITE "                Usuario: " << getUsername() << " | " << getDate() << endl;
    cout << CYAN "=============================================================================\n" RESET;

    cout << BOLD BBLUE "\n                      LIMPEZA DE SISTEMA\n" RESET;
    cout << CYAN "-----------------------------------------------------------------------------\n" RESET;
    cout << BBLUE "[1]  " RESET "Limpar Prefetch              " << BBLUE "[21] " RESET "Limpar Cache Navegadores\n";
    cout << BBLUE "[2]  " RESET "Limpar Temp Usuario          " << BBLUE "[22] " RESET "Limpar Arquivos Despejo (.dmp)\n";
    cout << BBLUE "[3]  " RESET "Limpar Temp Windows          " << BBLUE "[23] " RESET "Limpar Downloads Antigos (30d)\n";
    cout << BBLUE "[4]  " RESET "Limpar Lixeira               " << BBLUE "[24] " RESET "Limpar Cache de Fontes\n";
    cout << BBLUE "[5]  " RESET "Limpar Cache Update          " << BBLUE "[25] " RESET "Limpar Windows Defender\n";
    cout << BBLUE "[6]  " RESET "Limpar DNS                   " << BBLUE "[26] " RESET "Limpar Historico Clipboard\n";
    cout << BBLUE "[7]  " RESET "Limpar Historico Win+R       " << BRED  "[27] " RESET "LIMPAR TUDO (COMPLETO)\n";
    cout << BBLUE "[8]  " RESET "Limpar Windows.old\n";
    cout << BBLUE "[9]  " RESET "Limpar Cache Shaders\n";
    cout << BBLUE "[10] " RESET "Limpar Miniaturas\n";
    cout << BBLUE "[11] " RESET "Limpar Logs de Eventos\n";
    cout << BRED  "[12] " RESET "LIMPAR TUDO (TEMPS)\n";

    cout << BOLD YELLOW "\n                    REPARO E MANUTENCAO\n" RESET;
    cout << CYAN "-----------------------------------------------------------------------------\n" RESET;
    cout << YELLOW "[13] " RESET "SFC Scannow                  " << YELLOW "[28] " RESET "Resetar Firewall\n";
    cout << YELLOW "[14] " RESET "Reparo DISM (Avancado)       " << YELLOW "[29] " RESET "Verificar Saude Disco (SMART)\n";
    cout << YELLOW "[15] " RESET "CHKDSK (Reparo Disco)        " << YELLOW "[30] " RESET "Backup de Drivers\n";
    cout << YELLOW "[16] " RESET "Otimizar/Defrag Disco\n";
    cout << YELLOW "[17] " RESET "Resetar Rede/Winsock\n";
    cout << YELLOW "[18] " RESET "CRIAR PONTO RESTAURACAO\n";

    cout << BOLD PURPLE "\n                      REMOVER BLOATWARE\n" RESET;
    cout << CYAN "-----------------------------------------------------------------------------\n" RESET;
    cout << PURPLE "[19] " RESET "Remover GameBar              " << PURPLE "[31] " RESET "Remover Bloatware Completo\n";
    cout << PURPLE "[20] " RESET "Remover Xbox Apps\n";
    cout << PURPLE "[32] " RESET "Remover OneDrive\n";
    cout << PURPLE "[33] " RESET "Remover Office Hub\n";
    cout << PURPLE "[34] " RESET "Remover Widgets\n";

    cout << BOLD BGREEN "\n                   OTIMIZACAO E PERFORMANCE\n" RESET;
    cout << CYAN "-----------------------------------------------------------------------------\n" RESET;
    cout << BGREEN "[35] " RESET "Desativar Telemetria         " << BGREEN "[47] " RESET "Otimizar para SSD\n";
    cout << BGREEN "[36] " RESET "Ativar Telemetria            " << BGREEN "[48] " RESET "Desativar GameDVR\n";
    cout << BGREEN "[37] " RESET "Desativar Hibernacao         " << BGREEN "[49] " RESET "Ajustar Prioridade Sistema\n";
    cout << BGREEN "[38] " RESET "Desempenho Visual Max        " << BGREEN "[50] " RESET "Desativar SuperFetch\n";
    cout << BGREEN "[39] " RESET "Ativar Plano Desempenho Max  " << BGREEN "[51] " RESET "Modo Jogo - Ativar\n";
    cout << BGREEN "[40] " RESET "Desativar Cortana            " << BGREEN "[52] " RESET "Prioridade Alta Jogos\n";
    cout << BGREEN "[41] " RESET "Desativar Indexacao\n";
    cout << BGREEN "[42] " RESET "Desativar Animacoes Windows\n";
    cout << BGREEN "[43] " RESET "Desativar Transparencia\n";

    cout << BOLD BCYAN "\n                       PERSONALIZACAO\n" RESET;
    cout << CYAN "-----------------------------------------------------------------------------\n" RESET;
    cout << BCYAN "[44] " RESET "Menu Contexto Win10          " << BCYAN "[53] " RESET "Desativar Timeline\n";
    cout << BCYAN "[45] " RESET "Menu Contexto Win11          " << BCYAN "[54] " RESET "Desativar Localizacao\n";
    cout << BCYAN "[46] " RESET "Desativar Bing Iniciar       " << BCYAN "[55] " RESET "Desativar Feedback Windows\n";
    cout << BCYAN "[56] " RESET "Ativar Bing Iniciar          " << BCYAN "[56] " RESET "Bloquear Telemetria Firewall\n";
    cout << BCYAN "[57] " RESET "Mostrar Extensoes Arquivos\n";
    cout << BCYAN "[58] " RESET "Desativar Aero Shake\n";
    cout << BCYAN "[59] " RESET "Desativar ID Anuncios\n";

    cout << BOLD WHITE "\n                      DIAGNOSTICO E INFO\n" RESET;
    cout << CYAN "-----------------------------------------------------------------------------\n" RESET;
    cout << WHITE "[60] " RESET "Ver Temperatura CPU          " << WHITE "[68] " RESET "Ping Google/Cloudflare\n";
    cout << WHITE "[61] " RESET "Analisar Uso de Disco        " << WHITE "[69] " RESET "Ver IP Publico\n";
    cout << WHITE "[62] " RESET "Top 10 Processos RAM         " << WHITE "[70] " RESET "Otimizar TCP/IP\n";
    cout << WHITE "[63] " RESET "Listar Programas Inicializacao\n";
    cout << WHITE "[64] " RESET "Exportar Lista Programas\n";
    cout << WHITE "[65] " RESET "Lista Drivers Instalados\n";

    cout << BOLD BWHITE "\n                        FERRAMENTAS\n" RESET;
    cout << CYAN "-----------------------------------------------------------------------------\n" RESET;
    cout << BWHITE "[66] " RESET "Atualizar Tudo (Winget)      " << BWHITE "[71] " RESET "Abrir Editor Registro\n";
    cout << BWHITE "[67] " RESET "Abrir Servicos (MSC)         " << BWHITE "[72] " RESET "Abrir Gerenciador Tarefas\n";
    cout << BWHITE "[73] " RESET "Info Sistema (msinfo32)      " << BWHITE "[74] " RESET "Versao Windows (winver)\n";
    cout << BWHITE "[75] " RESET "Info Desenvolvedor\n";

    cout << RED "\n[0]  SAIR DO PROGRAMA\n" RESET;
    cout << CYAN "=============================================================================\n" RESET;
    cout << "Sua opcao: ";
}

//  LIMPEZA 
void func1() { cout << YELLOW "Limpando Prefetch...\n" RESET; system("del /q /f /s C:\\Windows\\Prefetch\\*.*"); }
void func2() { cout << YELLOW "Limpando Temp Usuario...\n" RESET; system("del /q /f /s %TEMP%\\*"); }
void func3() { cout << YELLOW "Limpando Temp Windows...\n" RESET; system("del /q /f /s C:\\Windows\\Temp\\*"); }
void func4() { cout << YELLOW "Limpando Lixeira...\n" RESET; system("rd /s /q C:\\$Recycle.Bin"); }
void func5() {
    cout << YELLOW "Limpando Cache Update...\n" RESET;
    system("net stop wuauserv & net stop bits");
    system("del /q /f /s C:\\Windows\\SoftwareDistribution\\Download\\*");
    system("net start wuauserv & net start bits");
}
void func6() { cout << YELLOW "Limpando DNS...\n" RESET; system("ipconfig /flushdns"); }
void func7() { cout << YELLOW "Limpando Historico Win+R...\n" RESET; system("reg delete \"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU\" /f"); }
void func8() { cout << YELLOW "Removendo Windows.old...\n" RESET; system("RD /S /Q %SystemDrive%\\Windows.old"); }
void func9() { cout << YELLOW "Limpando Cache Shaders...\n" RESET; system("del /q /f /s %LocalAppData%\\Microsoft\\DirectXShaderCache\\*"); }
void func10() { cout << YELLOW "Limpando Miniaturas...\n" RESET; system("del /q /f /s %LocalAppData%\\Microsoft\\Windows\\Explorer\\thumbcache_*.db"); }
void func11() { cout << YELLOW "Limpando Logs de Eventos...\n" RESET; system("for /F \"tokens=*\" %1 in ('wevtutil.exe el') DO wevtutil.exe cl \"%1\""); }
void func12() { cout << BRED "LIMPANDO TUDO (TEMPS)...\n" RESET; func1(); func2(); func3(); func4(); func5(); func6(); func7(); }

void func21() {
    cout << YELLOW "Limpando Cache Navegadores...\n" RESET;
    system("del /q /f /s %LocalAppData%\\Google\\Chrome\\User Data\\Default\\Cache\\*");
    system("del /q /f /s %LocalAppData%\\Microsoft\\Edge\\User Data\\Default\\Cache\\*");
    system("del /q /f /s %AppData%\\Mozilla\\Firefox\\Profiles\\*.default\\cache2\\*");
}
void func22() {
    cout << YELLOW "Limpando Arquivos Despejo...\n" RESET;
    system("del /q /f /s C:\\Windows\\Minidump\\*");
    system("del /q /f C:\\Windows\\memory.dmp");
}
void func23() { cout << YELLOW "Limpando Downloads Antigos (30 dias)...\n" RESET; system("forfiles /p %USERPROFILE%\\Downloads /s /m *.* /d -30 /c \"cmd /c del @path\" 2>nul"); }
void func24() {
    cout << YELLOW "Limpando Cache de Fontes...\n" RESET;
    system("net stop FontCache");
    system("del /q /f /s %WinDir%\\ServiceProfiles\\LocalService\\AppData\\Local\\FontCache\\*");
    system("net start FontCache");
}
void func25() { cout << YELLOW "Limpando Windows Defender...\n" RESET; system("del /q /f /s \"C:\\ProgramData\\Microsoft\\Windows Defender\\Scans\\History\\*\""); }
void func26() { cout << YELLOW "Limpando Historico Clipboard...\n" RESET; system("reg delete \"HKCU\\Software\\Microsoft\\Clipboard\" /f 2>nul"); }
void func27() { cout << BRED "LIMPEZA COMPLETA...\n" RESET; func1(); func2(); func3(); func4(); func5(); func6(); func7(); func8(); func9(); func10(); func21(); func22(); func24(); func25(); }

// REPARO
void func13() { cout << YELLOW "Executando SFC Scannow...\n" RESET; system("sfc /scannow"); }
void func14() { cout << YELLOW "Executando DISM...\n" RESET; system("dism /online /cleanup-image /restorehealth"); }
void func15() { cout << YELLOW "Agendando CHKDSK...\n" RESET; system("echo S | chkdsk C: /f"); }
void func16() { cout << YELLOW "Otimizando Disco...\n" RESET; system("defrag C: -f -v"); }
void func17() { cout << YELLOW "Resetando Rede...\n" RESET; system("netsh winsock reset & netsh int ip reset & ipconfig /release & ipconfig /renew & ipconfig /flushdns"); }
void func18() { cout << YELLOW "Criando Ponto Restauracao...\n" RESET; system("powershell -Command \"Checkpoint-Computer -Description 'Cleaner_Restore' -RestorePointType 'MODIFY_SETTINGS'\""); }
void func28() { cout << YELLOW "Resetando Firewall...\n" RESET; system("netsh advfirewall reset"); }
void func29() { cout << YELLOW "Verificando Saude do Disco...\n" RESET; system("wmic diskdrive get status"); }
void func30() { cout << YELLOW "Backup de Drivers...\n" RESET; system("dism /online /export-driver /destination:C:\\DriversBackup"); }

// BLOATWARE
void func19() {
    cout << YELLOW "Removendo GameBar...\n" RESET;
    system("powershell -Command \"Get-AppxPackage *Microsoft.XboxGamingOverlay* | Remove-AppxPackage\"");
    system("powershell -Command \"Get-AppxPackage *Microsoft.XboxGameOverlay* | Remove-AppxPackage\"");
}
void func20() { cout << YELLOW "Removendo Xbox Apps...\n" RESET; system("powershell -Command \"Get-AppxPackage *xbox* | Remove-AppxPackage\""); }
void func31() {
    cout << YELLOW "Removendo Bloatware Completo...\n" RESET;
    system("powershell -Command \"Get-AppxPackage *3dbuilder* | Remove-AppxPackage\"");
    system("powershell -Command \"Get-AppxPackage *windowscamera* | Remove-AppxPackage\"");
    system("powershell -Command \"Get-AppxPackage *officehub* | Remove-AppxPackage\"");
    system("powershell -Command \"Get-AppxPackage *skypeapp* | Remove-AppxPackage\"");
    system("powershell -Command \"Get-AppxPackage *getstarted* | Remove-AppxPackage\"");
    system("powershell -Command \"Get-AppxPackage *zunemusic* | Remove-AppxPackage\"");
    system("powershell -Command \"Get-AppxPackage *windowsmaps* | Remove-AppxPackage\"");
    system("powershell -Command \"Get-AppxPackage *solitairecollection* | Remove-AppxPackage\"");
    system("powershell -Command \"Get-AppxPackage *bingfinance* | Remove-AppxPackage\"");
    system("powershell -Command \"Get-AppxPackage *zunevideo* | Remove-AppxPackage\"");
    system("powershell -Command \"Get-AppxPackage *bingnews* | Remove-AppxPackage\"");
    system("powershell -Command \"Get-AppxPackage *onenote* | Remove-AppxPackage\"");
    system("powershell -Command \"Get-AppxPackage *people* | Remove-AppxPackage\"");
    system("powershell -Command \"Get-AppxPackage *windowsphone* | Remove-AppxPackage\"");
    system("powershell -Command \"Get-AppxPackage *photos* | Remove-AppxPackage\"");
    system("powershell -Command \"Get-AppxPackage *soundrecorder* | Remove-AppxPackage\"");
}
void func32() {
    cout << YELLOW "Removendo OneDrive...\n" RESET;
    system("taskkill /f /im OneDrive.exe >nul 2>&1");
    system("if exist %SystemRoot%\\SysWOW64\\OneDriveSetup.exe (%SystemRoot%\\SysWOW64\\OneDriveSetup.exe /uninstall) else (%SystemRoot%\\System32\\OneDriveSetup.exe /uninstall)");
    system("rd /s /q \"%UserProfile%\\OneDrive\" >nul 2>&1");
}
void func33() { cout << YELLOW "Removendo Office Hub...\n" RESET; system("powershell -Command \"Get-AppxPackage *Microsoft.MicrosoftOfficeHub* | Remove-AppxPackage\""); }
void func34() { cout << YELLOW "Removendo Widgets...\n" RESET; system("powershell -Command \"Get-AppxPackage *WebExperience* | Remove-AppxPackage\""); }

//  OTIMZACAO 
void func35() {
    cout << YELLOW "Desativando Telemetria...\n" RESET;
    system("sc stop DiagTrack & sc config DiagTrack start=disabled");
    system("sc stop dmwappushservice & sc config dmwappushservice start=disabled");
}
void func36() { cout << YELLOW "Ativando Telemetria...\n" RESET; system("sc config DiagTrack start=auto & sc start DiagTrack"); }
void func37() { cout << YELLOW "Desativando Hibernacao...\n" RESET; system("powercfg -h off"); }
void func38() {
    cout << YELLOW "Desempenho Visual Max...\n" RESET;
    system("reg add \"HKCU\\Control Panel\\Desktop\" /v UserPreferencesMask /t REG_BINARY /d 9012028010000000 /f");
    system("reg add \"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\VisualEffects\" /v VisualFXSetting /t REG_DWORD /d 2 /f");
}
void func39() { cout << YELLOW "Plano Desempenho Max...\n" RESET; system("powercfg -duplicatescheme e9a42b02-d5df-448d-aa00-03f14749eb61"); }
void func40() { cout << YELLOW "Desativando Cortana...\n" RESET; system("reg add \"HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Search\" /v AllowCortana /t REG_DWORD /d 0 /f"); }
void func41() { cout << YELLOW "Desativando Indexacao...\n" RESET; system("sc stop WSearch & sc config WSearch start=disabled"); }
void func42() { cout << YELLOW "Desativando Animacoes...\n" RESET; system("reg add \"HKCU\\Control Panel\\Desktop\\WindowMetrics\" /v MinAnimate /t REG_SZ /d 0 /f"); }
void func43() { cout << YELLOW "Desativando Transparencia...\n" RESET; system("reg add \"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize\" /v EnableTransparency /t REG_DWORD /d 0 /f"); }
void func47() { cout << YELLOW "Otimizando SSD...\n" RESET; system("schtasks /Change /TN \"Microsoft\\Windows\\Defrag\\ScheduledDefrag\" /DISABLE"); }
void func48() { cout << YELLOW "Desativando GameDVR...\n" RESET; system("reg add \"HKCU\\System\\GameConfigStore\" /v GameDVR_Enabled /t REG_DWORD /d 0 /f"); }
void func49() { cout << YELLOW "Ajustando Prioridade...\n" RESET; system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\PriorityControl\" /v Win32PrioritySeparation /t REG_DWORD /d 38 /f"); }
void func50() { cout << YELLOW "Desativando SuperFetch...\n" RESET; system("sc config SysMain start=disabled & sc stop SysMain"); }
void func51() { cout << YELLOW "Ativando Modo Jogo...\n" RESET; system("reg add \"HKCU\\Software\\Microsoft\\GameBar\" /v AllowAutoGameMode /t REG_DWORD /d 1 /f"); }
void func52() { cout << YELLOW "Prioridade Alta Jogos...\n" RESET; system("reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v Priority /t REG_DWORD /d 8 /f"); }

//  PERSONALIZACAO
void func44() { cout << YELLOW "Menu Contexto Win10...\n" RESET; system("reg add \"HKCU\\Software\\Classes\\CLSID\\{86ca1aa0-34aa-4e8b-a509-50c905bae2a2}\\InprocServer32\" /f /ve >nul 2>&1"); system("taskkill /f /im explorer.exe & start explorer.exe"); }
void func45() { cout << YELLOW "Menu Contexto Win11...\n" RESET; system("reg delete \"HKCU\\Software\\Classes\\CLSID\\{86ca1aa0-34aa-4e8b-a509-50c905bae2a2}\" /f >nul 2>&1"); system("taskkill /f /im explorer.exe & start explorer.exe"); }
void func46() { cout << YELLOW "Desativando Bing...\n" RESET; system("reg add \"HKCU\\Software\\Policies\\Microsoft\\Windows\\Explorer\" /v \"DisableSearchBoxSuggestions\" /t REG_DWORD /d 1 /f"); }
void func53() { cout << YELLOW "Desativando Timeline...\n" RESET; system("reg add \"HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\System\" /v EnableActivityFeed /t REG_DWORD /d 0 /f"); }
void func54() { cout << YELLOW "Desativando Localizacao...\n" RESET; system("reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\location\" /v Value /t REG_SZ /d Deny /f"); }
void func55() { cout << YELLOW "Desativando Feedback...\n" RESET; system("reg add \"HKCU\\Software\\Microsoft\\Siuf\\Rules\" /v NumberOfSIUFInPeriod /t REG_DWORD /d 0 /f"); }
void func56() { cout << YELLOW "Ativando Bing...\n" RESET; system("reg delete \"HKCU\\Software\\Policies\\Microsoft\\Windows\\Explorer\" /v \"DisableSearchBoxSuggestions\" /f"); }
void func57() { cout << YELLOW "Mostrando Extensoes...\n" RESET; system("reg add \"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced\" /v HideFileExt /t REG_DWORD /d 0 /f"); system("taskkill /f /im explorer.exe & start explorer.exe"); }
void func58() { cout << YELLOW "Desativando Aero Shake...\n" RESET; system("reg add \"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced\" /v DisallowShaking /t REG_DWORD /d 1 /f"); }
void func59() { cout << YELLOW "Desativando ID Anuncios...\n" RESET; system("reg add \"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\AdvertisingInfo\" /v Enabled /t REG_DWORD /d 0 /f"); }

//  DIAGNOSTICO 
void func60() { cout << YELLOW "Temperatura CPU...\n" RESET; system("wmic /namespace:\\\\root\\wmi PATH MSAcpi_ThermalZoneTemperature get CurrentTemperature"); }
void func61() { cout << YELLOW "Analisando Disco...\n" RESET; system("powershell \"Get-ChildItem C:\\ -Recurse -ErrorAction SilentlyContinue | Measure-Object -Property Length -Sum\""); }
void func62() { cout << YELLOW "Top 10 RAM...\n" RESET; system("powershell \"Get-Process | Sort-Object WS -Descending | Select-Object -First 10 | Format-Table Name,@{n='RAM(MB)';e={$_.WS/1MB -as [int]}}\""); }
void func63() { cout << YELLOW "Programas Inicializacao...\n" RESET; system("wmic startup get caption,command"); }
void func64() { cout << YELLOW "Exportando Lista Programas...\n" RESET; system("wmic product get name,version > C:\\programas_instalados.txt"); cout << GREEN "Salvo em C:\\programas_instalados.txt\n" RESET; }
void func65() { cout << YELLOW "Lista Drivers...\n" RESET; system("driverquery > C:\\drivers_lista.txt"); cout << GREEN "Salvo em C:\\drivers_lista.txt\n" RESET; }
void func68() { cout << YELLOW "Ping Google/Cloudflare...\n" RESET; system("ping 8.8.8.8 -n 4"); system("ping 1.1.1.1 -n 4"); }
void func69() { cout << YELLOW "Ver IP Publico...\n" RESET; system("curl ifconfig.me"); }
void func70() { cout << YELLOW "Otimizando TCP/IP...\n" RESET; system("netsh int tcp set global autotuninglevel=normal"); }

// FERRAMENTAS
void func66() { cout << YELLOW "Atualizando via Winget...\n" RESET; system("winget upgrade --all"); }
void func67() { cout << YELLOW "Abrindo Servicos...\n" RESET; system("start services.msc"); }
void func71() { cout << YELLOW "Abrindo Registro...\n" RESET; system("start regedit"); }
void func72() { cout << YELLOW "Abrindo Gerenciador Tarefas...\n" RESET; system("start taskmgr"); }
void func73() { cout << YELLOW "Info Sistema...\n" RESET; system("msinfo32"); }
void func74() { cout << YELLOW "Versao Windows...\n" RESET; system("winver"); }
void func75() {
    cout << CYAN "=============================================================================\n";
    cout << BOLD GREEN "                       DESENVOLVEDOR INFO\n" RESET;
    cout << CYAN "=============================================================================\n\n";
    cout << YELLOW " Criado por:  " << WHITE << "uDxkr" << endl;
    cout << YELLOW " GitHub:      " << BBLUE << "github.com/udxkr" << endl;
    cout << YELLOW " Website:     " << BBLUE << "dxkr.ct.ws" << endl;
    cout << YELLOW " Versao:      " << BGREEN << "2.0" << endl;
    cout << YELLOW " Status:      " << BGREEN << "Online & Coding" << endl;
    cout << CYAN "\n=============================================================================\n" RESET;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

    if (!isAdmin()) {
        cout << RED "Execute como Administrador!\n" RESET;
        pause();
        return 0;
    }

    int op;
    while (true) {
        menu();
        cin >> op;
        clearScreen();

        switch (op) {
        case 1: func1(); break;
        case 2: func2(); break;
        case 3: func3(); break;
        case 4: func4(); break;
        case 5: func5(); break;
        case 6: func6(); break;
        case 7: func7(); break;
        case 8: func8(); break;
        case 9: func9(); break;
        case 10: func10(); break;
        case 11: func11(); break;
        case 12: func12(); break;
        case 13: func13(); break;
        case 14: func14(); break;
        case 15: func15(); break;
        case 16: func16(); break;
        case 17: func17(); break;
        case 18: func18(); break;
        case 19: func19(); break;
        case 20: func20(); break;
        case 21: func21(); break;
        case 22: func22(); break;
        case 23: func23(); break;
        case 24: func24(); break;
        case 25: func25(); break;
        case 26: func26(); break;
        case 27: func27(); break;
        case 28: func28(); break;
        case 29: func29(); break;
        case 30: func30(); break;
        case 31: func31(); break;
        case 32: func32(); break;
        case 33: func33(); break;
        case 34: func34(); break;
        case 35: func35(); break;
        case 36: func36(); break;
        case 37: func37(); break;
        case 38: func38(); break;
        case 39: func39(); break;
        case 40: func40(); break;
        case 41: func41(); break;
        case 42: func42(); break;
        case 43: func43(); break;
        case 44: func44(); break;
        case 45: func45(); break;
        case 46: func46(); break;
        case 47: func47(); break;
        case 48: func48(); break;
        case 49: func49(); break;
        case 50: func50(); break;
        case 51: func51(); break;
        case 52: func52(); break;
        case 53: func53(); break;
        case 54: func54(); break;
        case 55: func55(); break;
        case 56: func56(); break;
        case 57: func57(); break;
        case 58: func58(); break;
        case 59: func59(); break;
        case 60: func60(); break;
        case 61: func61(); break;
        case 62: func62(); break;
        case 63: func63(); break;
        case 64: func64(); break;
        case 65: func65(); break;
        case 66: func66(); break;
        case 67: func67(); break;
        case 68: func68(); break;
        case 69: func69(); break;
        case 70: func70(); break;
        case 71: func71(); break;
        case 72: func72(); break;
        case 73: func73(); break;
        case 74: func74(); break;
        case 75: func75(); break;
        case 0: return 0;
        default: cout << RED "Opcao invalida!\n" RESET; break;
        }

        cout << GREEN "\nOperacao concluida com sucesso.\n" RESET;
        pause();
    }
}
