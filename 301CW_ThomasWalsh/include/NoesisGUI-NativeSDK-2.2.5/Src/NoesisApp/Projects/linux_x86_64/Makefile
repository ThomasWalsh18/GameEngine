# GNU Make project for 'NoesisApp'

# Parallel builds can be enabled using the environment variable MAKEFLAGS (eg: MAKEFLAGS="-j 4")
# For parallel execution in Windows, Make 4.0 or better is required

include ../../../../Config/Common.makeprops
include ../../../../Config/Profile/Profile.makeprops
include ../../../../Config/Release/Release.makeprops
include ../../../../Config/Debug/Debug.makeprops

SHELLTYPE = msdos
ifeq (, $(ComSpec)$(COMSPEC))
  SHELLTYPE = posix
endif
ifeq (/bin, $(findstring /bin, $(SHELL)))
  SHELLTYPE = posix
endif
ifeq (/bin, $(findstring /bin, $(MAKESHELL)))
  SHELLTYPE = posix
endif

ifeq (posix, $(SHELLTYPE))
  MKDIR = $(Q)mkdir -p "$(1)"
  BIN2H = ../../../Tools/Bin2h/bin2h.py
  CP = $(Q)cp "$(1)" "$(2)"
  RM = $(Q)rm -f "$(1)"
  RMTREE = $(Q)rm -rf "$(1)"
  FIXSLASHES = 
else
  MKDIR = $(Q)mkdir "$(subst /,\,$(1))" 2> nul || exit 0
  BIN2H = ..\..\..\Tools\Bin2h\bin2h.exe
  CP = $(Q)copy /Y "$(subst /,\,$(1))" "$(subst /,\,$(2))" > nul
  RM = $(Q)del /Q "$(subst /,\,$(1))" 2> nul || exit 0
  RMTREE = $(Q)rmdir /S /Q "$(subst /,\,$(1))" 2> nul || exit 0
  SED = ..\..\..\Tools\sed\sed.exe
  FIXSLASHES = $(Q)$(SED) -i "s/\(\S\)\\/\1\//g" "$(1)"
endif

ifeq ($(V), 1)
  Q =
else
  Q = @
endif

ifndef CONFIG
  CONFIG = Release
endif

ifeq ($(CONFIG), Profile)
  TARGET_DIR = ../../../../Bin/linux_x86_64
  TARGET = ../../../../Bin/linux_x86_64/libNoesisApp.so
  INTERMEDIATE = build/Profile
  LIB_DIRS = 
  LIBS = -lpthread -lGL -lX11 -lNoesis -ldl
  LIBS_DEPS = ../../../../Bin/linux_x86_64/libNoesis.so
  INCLUDES = -I../../../Packages/Gui/DependencySystem/Include -I../../../Packages/App/Display/Include -I../../../Packages/Gui/Providers/Include -I../../../Packages/Core/NSTL/Include -I../../../Packages/App/Launcher/Include -I../../../Packages/Gui/CachedFontProvider/Include -I../../../Packages/App/Providers/Include -I../../../Packages/Core/Kernel/Include -I../../../../Include -I../../../Packages/Math/VectorMath/Include -I../../../Packages/Gui/Core/Include -I../../../Packages/App/XDisplay/Include -I../../../Packages/Render/GLRenderDevice/Include -I../../../Packages/App/Interactivity/Include -I../../../../3rdParty/EASTL/local/include -I../../../Packages/App/ApplicationLauncher/Include -I../../../Packages/Render/RenderContext/Include -I../../../Packages/Render/RenderDevice/Include -I../../../Packages/Math/Utils/Include -I../../../Packages/App/DisplayLauncher/Include -I../../../Packages/Core/TypeConverter/Include -I../../../Packages/Drawing/Types/Include -I../../../Packages/Render/GLRenderContext/Include -I../../../Packages/Core/Nullable/Include -I../../../Packages/Gui/Animation/Include -Ibuild/Profile
  DEFINES = -DNS_BUILD -DNS_CONFIG=Profile -DNS_VERSION=2.2.5 -DNS_APP_FRAMEWORK -DNS_PROFILE -DNS_MINIMUM_LOG_LEVEL=2 -DNS_RENDER_RENDERCONTEXT_EXPORTS -DNS_RENDER_GLRENDERDEVICE_EXPORTS -DNS_APP_DISPLAY_EXPORTS -DNS_RENDER_GLRENDERCONTEXT_PRIVATE -DNS_APP_XDISPLAY_PRIVATE -DNS_APP_LAUNCHER_EXPORTS -DNS_APP_PROVIDERS_EXPORTS -DNS_APP_DISPLAYLAUNCHER_EXPORTS -DNS_APP_APPLICATIONLAUNCHER_EXPORTS -DNS_APP_INTERACTIVITY_EXPORTS
  CFLAGS = $(CFLAGS_PROFILE)
  CXXFLAGS = $(CXXFLAGS_PROFILE)
  LDFLAGS = $(LDFLAGS_PROFILE)
else ifeq ($(CONFIG), Release)
  TARGET_DIR = ../../../../Bin/linux_x86_64
  TARGET = ../../../../Bin/linux_x86_64/libNoesisApp.so
  INTERMEDIATE = build/Release
  LIB_DIRS = 
  LIBS = -lpthread -lGL -lX11 -lNoesis -ldl
  LIBS_DEPS = ../../../../Bin/linux_x86_64/libNoesis.so
  INCLUDES = -I../../../Packages/Gui/DependencySystem/Include -I../../../Packages/App/Display/Include -I../../../Packages/Gui/Providers/Include -I../../../Packages/Core/NSTL/Include -I../../../Packages/App/Launcher/Include -I../../../Packages/Gui/CachedFontProvider/Include -I../../../Packages/App/Providers/Include -I../../../Packages/Core/Kernel/Include -I../../../../Include -I../../../Packages/Math/VectorMath/Include -I../../../Packages/Gui/Core/Include -I../../../Packages/App/XDisplay/Include -I../../../Packages/Render/GLRenderDevice/Include -I../../../Packages/App/Interactivity/Include -I../../../../3rdParty/EASTL/local/include -I../../../Packages/App/ApplicationLauncher/Include -I../../../Packages/Render/RenderContext/Include -I../../../Packages/Render/RenderDevice/Include -I../../../Packages/Math/Utils/Include -I../../../Packages/App/DisplayLauncher/Include -I../../../Packages/Core/TypeConverter/Include -I../../../Packages/Drawing/Types/Include -I../../../Packages/Render/GLRenderContext/Include -I../../../Packages/Core/Nullable/Include -I../../../Packages/Gui/Animation/Include -Ibuild/Release
  DEFINES = -DNS_BUILD -DNS_CONFIG=Release -DNS_VERSION=2.2.5 -DNS_APP_FRAMEWORK -DNS_RENDER_RENDERCONTEXT_EXPORTS -DNS_RENDER_GLRENDERDEVICE_EXPORTS -DNS_APP_DISPLAY_EXPORTS -DNS_RENDER_GLRENDERCONTEXT_PRIVATE -DNS_APP_XDISPLAY_PRIVATE -DNS_APP_LAUNCHER_EXPORTS -DNS_APP_PROVIDERS_EXPORTS -DNS_APP_DISPLAYLAUNCHER_EXPORTS -DNS_APP_APPLICATIONLAUNCHER_EXPORTS -DNS_APP_INTERACTIVITY_EXPORTS
  CFLAGS = $(CFLAGS_RELEASE)
  CXXFLAGS = $(CXXFLAGS_RELEASE)
  LDFLAGS = $(LDFLAGS_RELEASE)
else ifeq ($(CONFIG), Debug)
  TARGET_DIR = ../../../../Bin/linux_x86_64
  TARGET = ../../../../Bin/linux_x86_64/libNoesisApp.so
  INTERMEDIATE = build/Debug
  LIB_DIRS = 
  LIBS = -lpthread -lGL -lX11 -lNoesis -ldl
  LIBS_DEPS = ../../../../Bin/linux_x86_64/libNoesis.so
  INCLUDES = -I../../../Packages/Gui/DependencySystem/Include -I../../../Packages/App/Display/Include -I../../../Packages/Gui/Providers/Include -I../../../Packages/Core/NSTL/Include -I../../../Packages/App/Launcher/Include -I../../../Packages/Gui/CachedFontProvider/Include -I../../../Packages/App/Providers/Include -I../../../Packages/Core/Kernel/Include -I../../../../Include -I../../../Packages/Math/VectorMath/Include -I../../../Packages/Gui/Core/Include -I../../../Packages/App/XDisplay/Include -I../../../Packages/Render/GLRenderDevice/Include -I../../../Packages/App/Interactivity/Include -I../../../../3rdParty/EASTL/local/include -I../../../Packages/App/ApplicationLauncher/Include -I../../../Packages/Render/RenderContext/Include -I../../../Packages/Render/RenderDevice/Include -I../../../Packages/Math/Utils/Include -I../../../Packages/App/DisplayLauncher/Include -I../../../Packages/Core/TypeConverter/Include -I../../../Packages/Drawing/Types/Include -I../../../Packages/Render/GLRenderContext/Include -I../../../Packages/Core/Nullable/Include -I../../../Packages/Gui/Animation/Include -Ibuild/Debug
  DEFINES = -DNS_BUILD -DNS_CONFIG=Debug -DNS_VERSION=2.2.5 -DNS_APP_FRAMEWORK -DNS_DEBUG -DNS_PROFILE -DNS_MINIMUM_LOG_LEVEL=1 -DNS_RENDER_RENDERCONTEXT_EXPORTS -DNS_RENDER_GLRENDERDEVICE_EXPORTS -DNS_APP_DISPLAY_EXPORTS -DNS_RENDER_GLRENDERCONTEXT_PRIVATE -DNS_APP_XDISPLAY_PRIVATE -DNS_APP_LAUNCHER_EXPORTS -DNS_APP_PROVIDERS_EXPORTS -DNS_APP_DISPLAYLAUNCHER_EXPORTS -DNS_APP_APPLICATIONLAUNCHER_EXPORTS -DNS_APP_INTERACTIVITY_EXPORTS
  CFLAGS = $(CFLAGS_DEBUG)
  CXXFLAGS = $(CXXFLAGS_DEBUG)
  LDFLAGS = $(LDFLAGS_DEBUG)
else
  $(error Invalid configuration '$(CONFIG)')
endif

PCH = $(INTERMEDIATE)/pch.h.gch
PCHFLAGS = -include $(INTERMEDIATE)/pch.h
DATA = $(INTERMEDIATE)/StatsOverlay.xaml.bin.h $(INTERMEDIATE)/dripicons-v2.ttf.bin.h

.SUFFIXES:
.PHONY: all prebuild data clean

all: prebuild $(TARGET)

prebuild:
	@echo ==== [NoesisApp] Building '$(CONFIG)' configuration ====

data: $(DATA)

$(INTERMEDIATE):
	$(call MKDIR,$(INTERMEDIATE))

$(TARGET_DIR):
	$(call MKDIR,$(TARGET_DIR))

$(PCH): pch/pch.h | $(INTERMEDIATE)
	@echo [PCH] [NoesisApp] $(notdir $<)
	$(Q)$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) -x c++-header -march=x86-64 -msse2 -mfpmath=sse -m64 -fPIC -c -MMD -MP -o $@ $<

$(INTERMEDIATE)/%.o: ../../../Packages/Render/RenderContext/Src/%.cpp $(PCH) | $(INTERMEDIATE) data
	@echo [CXX] [Render/RenderContext] $(notdir $<)
	$(Q)$(CXX) $(CXXFLAGS) $(PCHFLAGS) $(INCLUDES) $(DEFINES) -march=x86-64 -msse2 -mfpmath=sse -m64 -fPIC -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/Render/RenderContext/Src/%.c | $(INTERMEDIATE) data
	@echo [CC] [Render/RenderContext] $(notdir $<)
	$(Q)$(CC) $(CFLAGS) $(INCLUDES) $(DEFINES) -march=x86-64 -msse2 -mfpmath=sse -m64 -fPIC -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/Render/GLRenderDevice/Src/%.cpp $(PCH) | $(INTERMEDIATE) data
	@echo [CXX] [Render/GLRenderDevice] $(notdir $<)
	$(Q)$(CXX) $(CXXFLAGS) $(PCHFLAGS) $(INCLUDES) $(DEFINES) -march=x86-64 -msse2 -mfpmath=sse -m64 -fPIC -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/Render/GLRenderDevice/Src/%.c | $(INTERMEDIATE) data
	@echo [CC] [Render/GLRenderDevice] $(notdir $<)
	$(Q)$(CC) $(CFLAGS) $(INCLUDES) $(DEFINES) -march=x86-64 -msse2 -mfpmath=sse -m64 -fPIC -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/App/Display/Src/%.cpp $(PCH) | $(INTERMEDIATE) data
	@echo [CXX] [App/Display] $(notdir $<)
	$(Q)$(CXX) $(CXXFLAGS) $(PCHFLAGS) $(INCLUDES) $(DEFINES) -march=x86-64 -msse2 -mfpmath=sse -m64 -fPIC -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/App/Display/Src/%.c | $(INTERMEDIATE) data
	@echo [CC] [App/Display] $(notdir $<)
	$(Q)$(CC) $(CFLAGS) $(INCLUDES) $(DEFINES) -march=x86-64 -msse2 -mfpmath=sse -m64 -fPIC -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/Render/GLRenderContext/Src/%.cpp $(PCH) | $(INTERMEDIATE) data
	@echo [CXX] [Render/GLRenderContext] $(notdir $<)
	$(Q)$(CXX) $(CXXFLAGS) $(PCHFLAGS) $(INCLUDES) $(DEFINES) -march=x86-64 -msse2 -mfpmath=sse -m64 -fPIC -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/Render/GLRenderContext/Src/%.c | $(INTERMEDIATE) data
	@echo [CC] [Render/GLRenderContext] $(notdir $<)
	$(Q)$(CC) $(CFLAGS) $(INCLUDES) $(DEFINES) -march=x86-64 -msse2 -mfpmath=sse -m64 -fPIC -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/App/XDisplay/Src/%.cpp $(PCH) | $(INTERMEDIATE) data
	@echo [CXX] [App/XDisplay] $(notdir $<)
	$(Q)$(CXX) $(CXXFLAGS) $(PCHFLAGS) $(INCLUDES) $(DEFINES) -march=x86-64 -msse2 -mfpmath=sse -m64 -fPIC -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/App/XDisplay/Src/%.c | $(INTERMEDIATE) data
	@echo [CC] [App/XDisplay] $(notdir $<)
	$(Q)$(CC) $(CFLAGS) $(INCLUDES) $(DEFINES) -march=x86-64 -msse2 -mfpmath=sse -m64 -fPIC -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/App/Launcher/Src/%.cpp $(PCH) | $(INTERMEDIATE) data
	@echo [CXX] [App/Launcher] $(notdir $<)
	$(Q)$(CXX) $(CXXFLAGS) $(PCHFLAGS) $(INCLUDES) $(DEFINES) -march=x86-64 -msse2 -mfpmath=sse -m64 -fPIC -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/App/Launcher/Src/%.c | $(INTERMEDIATE) data
	@echo [CC] [App/Launcher] $(notdir $<)
	$(Q)$(CC) $(CFLAGS) $(INCLUDES) $(DEFINES) -march=x86-64 -msse2 -mfpmath=sse -m64 -fPIC -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/App/Providers/Src/%.cpp $(PCH) | $(INTERMEDIATE) data
	@echo [CXX] [App/Providers] $(notdir $<)
	$(Q)$(CXX) $(CXXFLAGS) $(PCHFLAGS) $(INCLUDES) $(DEFINES) -march=x86-64 -msse2 -mfpmath=sse -m64 -fPIC -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/App/Providers/Src/%.c | $(INTERMEDIATE) data
	@echo [CC] [App/Providers] $(notdir $<)
	$(Q)$(CC) $(CFLAGS) $(INCLUDES) $(DEFINES) -march=x86-64 -msse2 -mfpmath=sse -m64 -fPIC -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/App/DisplayLauncher/Src/%.cpp $(PCH) | $(INTERMEDIATE) data
	@echo [CXX] [App/DisplayLauncher] $(notdir $<)
	$(Q)$(CXX) $(CXXFLAGS) $(PCHFLAGS) $(INCLUDES) $(DEFINES) -march=x86-64 -msse2 -mfpmath=sse -m64 -fPIC -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/App/DisplayLauncher/Src/%.c | $(INTERMEDIATE) data
	@echo [CC] [App/DisplayLauncher] $(notdir $<)
	$(Q)$(CC) $(CFLAGS) $(INCLUDES) $(DEFINES) -march=x86-64 -msse2 -mfpmath=sse -m64 -fPIC -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/App/ApplicationLauncher/Src/%.cpp $(PCH) | $(INTERMEDIATE) data
	@echo [CXX] [App/ApplicationLauncher] $(notdir $<)
	$(Q)$(CXX) $(CXXFLAGS) $(PCHFLAGS) $(INCLUDES) $(DEFINES) -march=x86-64 -msse2 -mfpmath=sse -m64 -fPIC -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/App/ApplicationLauncher/Src/%.c | $(INTERMEDIATE) data
	@echo [CC] [App/ApplicationLauncher] $(notdir $<)
	$(Q)$(CC) $(CFLAGS) $(INCLUDES) $(DEFINES) -march=x86-64 -msse2 -mfpmath=sse -m64 -fPIC -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/StatsOverlay.xaml.bin.h: ../../../Packages/App/ApplicationLauncher/Src/StatsOverlay.xaml | $(INTERMEDIATE)
	@echo [BIN] [App/ApplicationLauncher] $(notdir $<)
	$(Q)$(BIN2H) "../../../Packages/App/ApplicationLauncher/Src/StatsOverlay.xaml" > "$(INTERMEDIATE)/StatsOverlay.xaml.bin.h" 

$(INTERMEDIATE)/dripicons-v2.ttf.bin.h: ../../../Packages/App/ApplicationLauncher/Src/dripicons-v2.ttf | $(INTERMEDIATE)
	@echo [BIN] [App/ApplicationLauncher] $(notdir $<)
	$(Q)$(BIN2H) "../../../Packages/App/ApplicationLauncher/Src/dripicons-v2.ttf" > "$(INTERMEDIATE)/dripicons-v2.ttf.bin.h" 

$(INTERMEDIATE)/%.o: ../../../Packages/App/Interactivity/Src/%.cpp $(PCH) | $(INTERMEDIATE) data
	@echo [CXX] [App/Interactivity] $(notdir $<)
	$(Q)$(CXX) $(CXXFLAGS) $(PCHFLAGS) $(INCLUDES) $(DEFINES) -march=x86-64 -msse2 -mfpmath=sse -m64 -fPIC -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/App/Interactivity/Src/%.c | $(INTERMEDIATE) data
	@echo [CC] [App/Interactivity] $(notdir $<)
	$(Q)$(CC) $(CFLAGS) $(INCLUDES) $(DEFINES) -march=x86-64 -msse2 -mfpmath=sse -m64 -fPIC -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/init.o: init.cpp $(PCH) | $(INTERMEDIATE)
	@echo [CXX] [NoesisApp] $(notdir $<)
	$(Q)$(CXX) $(CXXFLAGS) $(PCHFLAGS) $(INCLUDES) $(DEFINES) -march=x86-64 -msse2 -mfpmath=sse -m64 -fPIC -c -MMD -MP -o $@ $<

$(TARGET): $(LIBS_DEPS) $(INTERMEDIATE)/init.o $(INTERMEDIATE)/Render.RenderContext.o $(INTERMEDIATE)/RenderContext.o $(INTERMEDIATE)/Image.o $(INTERMEDIATE)/GLRenderDevice.o $(INTERMEDIATE)/Render.GLRenderDevice.o $(INTERMEDIATE)/Display.o $(INTERMEDIATE)/App.Display.o $(INTERMEDIATE)/Audio.mm.o $(INTERMEDIATE)/Render.GLRenderContext.o $(INTERMEDIATE)/GLRenderContext.mm.o $(INTERMEDIATE)/Gui.XDisplay.o $(INTERMEDIATE)/XDisplay.o $(INTERMEDIATE)/App.Launcher.o $(INTERMEDIATE)/CommandLine.o $(INTERMEDIATE)/Launcher.o $(INTERMEDIATE)/FileTextureProvider.o $(INTERMEDIATE)/EmbeddedFontProvider.o $(INTERMEDIATE)/EmbeddedXamlProvider.o $(INTERMEDIATE)/LocalXamlProvider.o $(INTERMEDIATE)/LocalFontProvider.o $(INTERMEDIATE)/App.Providers.o $(INTERMEDIATE)/EmbeddedTextureProvider.o $(INTERMEDIATE)/LocalTextureProvider.o $(INTERMEDIATE)/App.DisplayLauncher.o $(INTERMEDIATE)/DisplayLauncher.o $(INTERMEDIATE)/App.ApplicationLauncher.o $(INTERMEDIATE)/NotifyPropertyChangedBase.o $(INTERMEDIATE)/ApplicationLauncher.o $(INTERMEDIATE)/Application.o $(INTERMEDIATE)/DelegateCommand.o $(INTERMEDIATE)/Window.o $(INTERMEDIATE)/TriggerBase.Interactivity.o $(INTERMEDIATE)/DataBindingHelper.o $(INTERMEDIATE)/ComparisonCondition.o $(INTERMEDIATE)/TargetedTriggerAction.o $(INTERMEDIATE)/TriggerAction.Interactivity.o $(INTERMEDIATE)/TranslateZoomRotateBehavior.o $(INTERMEDIATE)/TimerTrigger.o $(INTERMEDIATE)/StoryboardTrigger.o $(INTERMEDIATE)/TriggerCollection.o $(INTERMEDIATE)/ControlStoryboardAction.o $(INTERMEDIATE)/App.Interactivity.o $(INTERMEDIATE)/ConditionalExpression.o $(INTERMEDIATE)/StoryboardCompletedTrigger.o $(INTERMEDIATE)/MouseDragElementBehavior.o $(INTERMEDIATE)/EventTrigger.Interactivity.o $(INTERMEDIATE)/LaunchUriOrFileAction.o $(INTERMEDIATE)/InvokeCommandAction.o $(INTERMEDIATE)/SetFocusAction.o $(INTERMEDIATE)/PropertyChangedTrigger.o $(INTERMEDIATE)/PlaySoundAction.o $(INTERMEDIATE)/BehaviorCollection.o $(INTERMEDIATE)/DataTrigger.Interactivity.o $(INTERMEDIATE)/StyleInteraction.o $(INTERMEDIATE)/RemoveElementAction.o $(INTERMEDIATE)/TriggerActionCollection.o $(INTERMEDIATE)/KeyTrigger.o $(INTERMEDIATE)/ConditionBehavior.o $(INTERMEDIATE)/EventTriggerBase.o $(INTERMEDIATE)/SelectAction.o $(INTERMEDIATE)/StoryboardAction.o $(INTERMEDIATE)/Behavior.o $(INTERMEDIATE)/GamepadTrigger.o $(INTERMEDIATE)/SelectAllAction.o $(INTERMEDIATE)/ChangePropertyAction.o $(INTERMEDIATE)/ComparisonLogic.o $(INTERMEDIATE)/AttachableObject.o $(INTERMEDIATE)/GoToStateAction.o $(INTERMEDIATE)/Interaction.o | $(TARGET_DIR)
	@echo [LD] $(notdir $@)
	+$(Q)$(CXX) $(LDFLAGS) -march=x86-64 -msse2 -mfpmath=sse -m64 -shared -Wl,--no-undefined -Wl,-soname,libNoesisApp.so -Wl,-rpath,\$$ORIGIN -Wl,-rpath,../../../../Bin/linux_x86_64 -L../../../../Bin/linux_x86_64 $(LIB_DIRS) -o $(TARGET) @$(CONFIG).rsp $(LIBS)
	@echo [STRIP] $(notdir $@)
	$(Q)objcopy --only-keep-debug $(TARGET) $(TARGET).debug
	$(Q)strip --strip-unneeded $(TARGET)
	$(Q)objcopy --add-gnu-debuglink=$(TARGET).debug $(TARGET)

-include $(INTERMEDIATE)/init.d $(INTERMEDIATE)/pch.h.d $(INTERMEDIATE)/Render.RenderContext.d $(INTERMEDIATE)/RenderContext.d $(INTERMEDIATE)/Image.d $(INTERMEDIATE)/GLRenderDevice.d $(INTERMEDIATE)/Render.GLRenderDevice.d $(INTERMEDIATE)/Display.d $(INTERMEDIATE)/App.Display.d $(INTERMEDIATE)/Audio.mm.d $(INTERMEDIATE)/Render.GLRenderContext.d $(INTERMEDIATE)/GLRenderContext.mm.d $(INTERMEDIATE)/Gui.XDisplay.d $(INTERMEDIATE)/XDisplay.d $(INTERMEDIATE)/App.Launcher.d $(INTERMEDIATE)/CommandLine.d $(INTERMEDIATE)/Launcher.d $(INTERMEDIATE)/FileTextureProvider.d $(INTERMEDIATE)/EmbeddedFontProvider.d $(INTERMEDIATE)/EmbeddedXamlProvider.d $(INTERMEDIATE)/LocalXamlProvider.d $(INTERMEDIATE)/LocalFontProvider.d $(INTERMEDIATE)/App.Providers.d $(INTERMEDIATE)/EmbeddedTextureProvider.d $(INTERMEDIATE)/LocalTextureProvider.d $(INTERMEDIATE)/App.DisplayLauncher.d $(INTERMEDIATE)/DisplayLauncher.d $(INTERMEDIATE)/App.ApplicationLauncher.d $(INTERMEDIATE)/NotifyPropertyChangedBase.d $(INTERMEDIATE)/ApplicationLauncher.d $(INTERMEDIATE)/Application.d $(INTERMEDIATE)/DelegateCommand.d $(INTERMEDIATE)/Window.d $(INTERMEDIATE)/TriggerBase.Interactivity.d $(INTERMEDIATE)/DataBindingHelper.d $(INTERMEDIATE)/ComparisonCondition.d $(INTERMEDIATE)/TargetedTriggerAction.d $(INTERMEDIATE)/TriggerAction.Interactivity.d $(INTERMEDIATE)/TranslateZoomRotateBehavior.d $(INTERMEDIATE)/TimerTrigger.d $(INTERMEDIATE)/StoryboardTrigger.d $(INTERMEDIATE)/TriggerCollection.d $(INTERMEDIATE)/ControlStoryboardAction.d $(INTERMEDIATE)/App.Interactivity.d $(INTERMEDIATE)/ConditionalExpression.d $(INTERMEDIATE)/StoryboardCompletedTrigger.d $(INTERMEDIATE)/MouseDragElementBehavior.d $(INTERMEDIATE)/EventTrigger.Interactivity.d $(INTERMEDIATE)/LaunchUriOrFileAction.d $(INTERMEDIATE)/InvokeCommandAction.d $(INTERMEDIATE)/SetFocusAction.d $(INTERMEDIATE)/PropertyChangedTrigger.d $(INTERMEDIATE)/PlaySoundAction.d $(INTERMEDIATE)/BehaviorCollection.d $(INTERMEDIATE)/DataTrigger.Interactivity.d $(INTERMEDIATE)/StyleInteraction.d $(INTERMEDIATE)/RemoveElementAction.d $(INTERMEDIATE)/TriggerActionCollection.d $(INTERMEDIATE)/KeyTrigger.d $(INTERMEDIATE)/ConditionBehavior.d $(INTERMEDIATE)/EventTriggerBase.d $(INTERMEDIATE)/SelectAction.d $(INTERMEDIATE)/StoryboardAction.d $(INTERMEDIATE)/Behavior.d $(INTERMEDIATE)/GamepadTrigger.d $(INTERMEDIATE)/SelectAllAction.d $(INTERMEDIATE)/ChangePropertyAction.d $(INTERMEDIATE)/ComparisonLogic.d $(INTERMEDIATE)/AttachableObject.d $(INTERMEDIATE)/GoToStateAction.d $(INTERMEDIATE)/Interaction.d

clean:
	@echo ==== [NoesisApp] Cleaning '$(CONFIG)' configuration ====
	$(call RMTREE,$(INTERMEDIATE))
	$(call RM,$(TARGET))
	$(call RM,$(TARGET).debug)
