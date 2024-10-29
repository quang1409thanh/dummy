from building import *
import json
import os

print(f"Start build app/app SConscript:")

# Khởi tạo Environment với các thiết lập cơ bản và ghi log
env = Environment()

# Log các file SConscript
for sc in Glob('*/SConscript'):
    SConscript(sc)
    print(f"Đã nạp SConscript: {sc}")

# Lấy thư mục hiện tại
CWD = GetCurrentDir()
print(f"Thư mục hiện tại: {CWD}")

# Gọi generate và log các file json
generate_files = Glob('config/*/*.json')
# log file json 
for file in generate_files:
    print(f"File JSON cấu hình: {file}")
generate(generate_files)

objsApp = Glob('*.c') + Glob('src/*.c')
# print("Danh sách file .c cho Application:", objsApp)

for obj in objsApp:
    print("File .c cho Application:", obj)

# Biến môi trường cho DL (Data Layer)
LL_DL = os.getenv('LL_DL')
print("Biến môi trường LL_DL:", LL_DL)


class ApplicationApp(Application):
    def config(self):
        self.CPPDEFINES = []
        self.CPPPATH = ['$INFRAS', f'{CWD}/include', CWD, '$Com_Cfg', '$StdTrace_Cfg']
        self.LIBS = ['StdTimer']
        for libName, source in self.libsForApp.items():
            self.LIBS.append(libName)
            self.RegisterConfig(libName, source)
            self.Append(CPPDEFINES=[f'USE_{libName.split(":")[0].upper()}'])
        self.source = objsApp


libsCommon = {
    'Dcm': Glob('config/Dcm/GEN/Dcm_Cfg.c'),
    'Dem': Glob('config/Dcm/GEN/Dem_Cfg.c'),
    'NvM': Glob('config/NvM/GEN/NvM_Cfg.c'),
}

with open(Glob('config/NvM/NvM.json')[0].rstr()) as f:
    cfg = json.load(f)
    nvmTarget = os.getenv('NVM_TARGET', cfg.get('target', 'Ea'))
libsCommon[nvmTarget] = Glob(f'config/NvM/GEN/{nvmTarget}_Cfg.c')

if 'Fee' in libsCommon:
    libsCommon['Fls'] = Glob('config/NvM/Fls_Cfg.c')
if 'Ea' in libsCommon:
    libsCommon['Eep'] = Glob('config/NvM/Eep_Cfg.c')

libsForCanApp = {
    'OsekNm': Glob('config/OsekNm_Cfg.c'),
    'CanNm': Glob('config/CanNm_Cfg.c'),
    'Com': Glob('config/Com/GEN/Com_Cfg.c'),
    'CanTp': Glob('config/CanTp/GEN/CanTp_Cfg.c'),
    'PduR': Glob('config/Com/GEN/PduR_Cfg.c'),
    'CanIf': Glob('config/Com/GEN/CanIf_Cfg.c'),
    'CanTSyn': Glob('config/CanTSyn/master/CanTSyn_Cfg.c'),
    'StdTrace': Glob('config/Trace/GEN/TraceApp_Cfg.c'),
}
libsForCanApp.update(libsCommon)

objsTraceTestCfg = Glob('config/GEN/TraceTest_Cfg.c')


@register_application
class ApplicationCanApp(ApplicationApp):
    def platform_config(self):
        self.Append(CPPDEFINES=['USE_STD_DEBUG', 'USE_PLUGIN'])
        self.Append(CPPDEFINES=['FEE_USE_BLANK_CHECK', 'FLS_ERASED_VALUE=0xFF'])
        self.Append(CPPDEFINES=['FLS_DIRECT_ACCESS'])
        self.LIBS.extend(['Simulator', 'Plugin'])
        self.Append(CPPDEFINES=['USE_TRACE_APP'])

        # Log các thư viện đang sử dụng
        print("Thư viện của CanApp:", self.LIBS)

    def config(self):
        if LL_DL:
            self.Append(CPPDEFINES=[f'CANTP_LL_DL={LL_DL}'])
        self.libsForApp = libsForCanApp
        super().config()
        self.Append(CPPDEFINES=['USE_CAN'])

        self.platform_config()
        # Log từng file .c sẽ được build
        for src in self.source:
            print("Đang biên dịch file nguồn:", src)

        # Gọi build_summary
        self.build_summary()

    def build_summary(self):
        print("=== Tóm tắt cấu hình cho CanApp ===")
        print("Nguồn của CanApp:", self.source)
        print("Thư viện của CanApp:", self.LIBS)
        for lib in self.LIBS:
            print("Thư viện trong libs:", lib)
        print("Đường dẫn include của CanApp:", self.CPPPATH)
        print("Định nghĩa tiền xử lý của CanApp:", self.CPPDEFINES)
        print("===================================")


objsSwc = Glob('config/SWC/*/*.c')
