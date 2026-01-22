#  WindowsOptimizer — Cleaner & Debloater PRO

<p align="center">
  <img src="https://img.shields.io/badge/Windows-11-0078D6?style=for-the-badge&logo=windows&logoColor=white" />
  <img src="https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" />
  <img src="https://img.shields.io/badge/License-MIT-green?style=for-the-badge" />
  <img src="https://img.shields.io/github/stars/udxkr/WindowsOptimizer?style=for-the-badge" />
</p>

##  Descrição

`WindowsOptimizer` é uma poderosa ferramenta de console em C++ com **75+ funcionalidades** para limpeza, otimização, reparo e remoção de bloatware do Windows 10/11. Interface intuitiva baseada em menu numérico colorido.

###  Destaques
-  **Limpeza profunda** de cache, temp, logs e arquivos desnecessários
-  **Otimização de performance** com ajustes de registro e serviços
- **Remoção de bloatware** (Xbox, OneDrive, Cortana, Widgets, etc.)
-  **Ferramentas de reparo** (SFC, DISM, CHKDSK)
- **Diagnóstico do sistema** (temperatura, RAM, disco)
-  **Personalização** (menu contexto, transparência, animações)

---

##  Aviso de Segurança

> **ATENÇÃO:** Muitas operações são destrutivas e irreversíveis!

**Antes de usar:**
-  Faça backup dos seus dados importantes
-  Crie um ponto de restauração (opção `18`)
-  Leia o que cada opção faz antes de executar

---

##  Requisitos

- **SO:** Windows 10 / Windows 11 (x64 recomendado)
- **Permissões:** Conta de Administrador
- **Compilador:** MSVC (Visual Studio 2019+) ou MinGW-w64
- **Ferramentas opcionais:** PowerShell, winget, curl, wmic

---
##  Compilar

### Método 1: Visual Studio
```bash
1. Abra WindowsOptimizer.sln no Visual Studio
2. Selecione Release/x64
3. Build > Build Solution (Ctrl+Shift+B)
```

### Método 2: Linha de Comando (MSBuild)
```cmd
msbuild WindowsOptimizer.sln /p:Configuration=Release /p:Platform=x64
```

### Método 3: G++ (MinGW)
```cmd
g++ -o WindowsOptimizer.exe main.cpp -std=c++17 -O2 -static
```

---

##  Executar
```cmd
# 1. Abra CMD/PowerShell como Administrador (IMPORTANTE!)
# 2. Navegue até a pasta do executável
cd caminho\para\WindowsOptimizer

# 3. Execute
.\WindowsOptimizer.exe
```

---

##  Funcionalidades

###  Limpeza de Sistema (1-27)
| Opção | Descrição |
|-------|-----------|
| 1-11  | Limpar Prefetch, Temp, Lixeira, Cache, DNS, Logs, etc. |
| 12    | **LIMPAR TUDO (TEMPS)** |
| 21-26 | Cache navegadores, arquivos .dmp, downloads antigos, fontes |
| 27    | **LIMPEZA COMPLETA** (tudo acima) |

###  Reparo e Manutenção (13-30)
- `13` SFC Scannow
- `14` Reparo DISM
- `15` CHKDSK
- `16` Desfragmentação
- `17` Reset de rede
- `18` **Criar ponto de restauração**
- `28-30` Firewall, SMART, Backup drivers

###  Remover Bloatware (19-34)
- Xbox, GameBar, OneDrive, Office Hub, Widgets
- `31` **Remoção completa** (15+ apps)

###  Otimização (35-52)
- Desativar telemetria, hibernação, indexação
- Modo de desempenho máximo
- Ajustes visuais, SSD, GameDVR
- Modo Jogo, prioridade para jogos

###  Personalização (44-59)
- Menu contexto Win10/Win11
- Desativar Bing, Timeline, Cortana
- Transparência, animações, Aero Shake

###  Diagnóstico (60-70)
- Temperatura CPU
- Uso de disco e RAM
- Top processos
- Ping, IP público, TCP/IP

###  Ferramentas (66-75)
- Atualizar via Winget
- Registro, Task Manager, msinfo32
- Exportar listas de programas/drivers

---

##  Screenshots
```
=============================================================================
                    CLEANER & DEBLOATER PRO v2.0
                Usuario: YourName | 22/01/2026
=============================================================================

                      LIMPEZA DE SISTEMA
-----------------------------------------------------------------------------
[1]  Limpar Prefetch              [21] Limpar Cache Navegadores
[2]  Limpar Temp Usuario          [22] Limpar Arquivos Despejo (.dmp)
...
```

---

##  Contribuição

Contribuições são bem-vindas! Para contribuir:

1. Fork o projeto
2. Crie uma branch (`git checkout -b feature/NovaFuncionalidade`)
3. Commit suas mudanças (`git commit -m 'Add: Nova funcionalidade'`)
4. Push para a branch (`git push origin feature/NovaFuncionalidade`)
5. Abra um Pull Request

**Diretrizes:**
- Mantenha o estilo de código consistente
- Teste em ambiente controlado (VM recomendada)
- Documente mudanças no README
- Adicione comentários em código complexo

---

##  Changelog

### v2.0 (Janeiro 2026)
-  75+ funcionalidades (vs 40 da v1.0)
-  Menu organizado em categorias
-  Novas limpezas: navegadores, .dmp, fontes
-  Diagnóstico: temperatura, RAM, disco
-  Otimizações para gaming
-  Correções diversas

### v1.0 (2025)
-  Lançamento inicial com 40 opções

---

##  Licença

Este projeto está licenciado sob a **MIT License** - veja o arquivo [LICENSE](LICENSE) para detalhes.

---

##  Autor

**uDxkr**

[![GitHub](https://img.shields.io/badge/GitHub-udxkr-181717?style=for-the-badge&logo=github)](https://github.com/udxkr)
[![Website](https://img.shields.io/badge/Website-dxkr.ct.ws-4285F4?style=for-the-badge&logo=google-chrome&logoColor=white)](https://dxkr.ct.ws)

---

##  Apoie o Projeto

Se este projeto foi útil para você, considere dar uma ⭐ no GitHub!

[![Star](https://img.shields.io/github/stars/udxkr/WindowsOptimizer?style=social)](https://github.com/udxkr/WindowsOptimizer)

---

##  Notas Importantes

-  **Recomento testares em VM primeiro** antes de usar no sistema principal
-  Algumas funcionalidades requerem reinicialização
-  Sempre crie ponto de restauração antes
-  Leia a documentação de cada opção antes de usar

---

<p align="center">
  Feito com ❤️ por <a href="https://github.com/udxkr">uDxkr</a>
</p>