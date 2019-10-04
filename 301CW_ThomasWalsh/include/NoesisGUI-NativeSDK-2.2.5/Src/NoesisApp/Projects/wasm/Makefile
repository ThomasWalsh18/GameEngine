# GNU Make project for 'NoesisApp'

# Parallel builds can be enabled using the environment variable MAKEFLAGS (eg: MAKEFLAGS="-j 4")
# For parallel execution in Windows, Make 4.0 or better is required

include ../../../../Config/Common.wasm.makeprops
include ../../../../Config/Debug/Debug.wasm.makeprops
include ../../../../Config/Profile/Profile.wasm.makeprops
include ../../../../Config/Release/Release.wasm.makeprops

CC = emcc
CXX = em++

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

ifeq ($(CONFIG), Debug)
  TARGET_DIR = ../../../../Bin/wasm
  TARGET = ../../../../Bin/wasm/NoesisApp.bc
  INTERMEDIATE = build/Debug
  LIB_DIRS = 
  LIBS = 
  LIBS_DEPS = 
  INCLUDES = -I../../../Packages/Gui/DependencySystem/Include -I../../../Packages/Render/RenderDevice/Include -I../../../Packages/Math/Utils/Include -I../../../Packages/App/EmscriptenDisplay/Include -I../../../Packages/Gui/CachedFontProvider/Include -I../../../Packages/Drawing/Types/Include -I../../../Packages/Core/NSTL/Include -I../../../Packages/Render/GLRenderDevice/Include -I../../../Packages/Core/Nullable/Include -I../../../Packages/App/Display/Include -I../../../Packages/Core/TypeConverter/Include -I../../../Packages/App/ApplicationLauncher/Include -I../../../Packages/Gui/Animation/Include -I../../../Packages/Gui/Core/Include -I../../../Packages/Math/VectorMath/Include -I../../../Packages/App/Launcher/Include -I../../../../Include -I../../../Packages/Render/GLRenderContext/Include -I../../../Packages/Render/RenderContext/Include -I../../../Packages/Gui/Providers/Include -I../../../Packages/App/DisplayLauncher/Include -I../../../Packages/App/Providers/Include -I../../../../3rdParty/EASTL/local/include -I../../../Packages/App/Interactivity/Include -I../../../Packages/Core/Kernel/Include -Ibuild/Debug
  DEFINES = -DNS_BUILD -DNS_CONFIG=Debug -DNS_VERSION=2.2.5 -DNS_APP_FRAMEWORK -DNS_STATIC_LIBRARY -DNS_DEBUG -DNS_PROFILE -DNS_MINIMUM_LOG_LEVEL=1 -DNS_RENDER_RENDERCONTEXT_EXPORTS -DNS_RENDER_GLRENDERDEVICE_EXPORTS -DNS_APP_DISPLAY_EXPORTS -DNS_RENDER_GLRENDERCONTEXT_PRIVATE -DNS_APP_LAUNCHER_EXPORTS -DNS_APP_PROVIDERS_EXPORTS -DNS_APP_DISPLAYLAUNCHER_EXPORTS -DNS_APP_APPLICATIONLAUNCHER_EXPORTS -DNS_APP_INTERACTIVITY_EXPORTS
  CFLAGS = $(CFLAGS_DEBUG)
  CXXFLAGS = $(CXXFLAGS_DEBUG)
  LDFLAGS = $(LDFLAGS_DEBUG)
else ifeq ($(CONFIG), Profile)
  TARGET_DIR = ../../../../Bin/wasm
  TARGET = ../../../../Bin/wasm/NoesisApp.bc
  INTERMEDIATE = build/Profile
  LIB_DIRS = 
  LIBS = 
  LIBS_DEPS = 
  INCLUDES = -I../../../Packages/Gui/DependencySystem/Include -I../../../Packages/Render/RenderDevice/Include -I../../../Packages/Math/Utils/Include -I../../../Packages/App/EmscriptenDisplay/Include -I../../../Packages/Gui/CachedFontProvider/Include -I../../../Packages/Drawing/Types/Include -I../../../Packages/Core/NSTL/Include -I../../../Packages/Render/GLRenderDevice/Include -I../../../Packages/Core/Nullable/Include -I../../../Packages/App/Display/Include -I../../../Packages/Core/TypeConverter/Include -I../../../Packages/App/ApplicationLauncher/Include -I../../../Packages/Gui/Animation/Include -I../../../Packages/Gui/Core/Include -I../../../Packages/Math/VectorMath/Include -I../../../Packages/App/Launcher/Include -I../../../../Include -I../../../Packages/Render/GLRenderContext/Include -I../../../Packages/Render/RenderContext/Include -I../../../Packages/Gui/Providers/Include -I../../../Packages/App/DisplayLauncher/Include -I../../../Packages/App/Providers/Include -I../../../../3rdParty/EASTL/local/include -I../../../Packages/App/Interactivity/Include -I../../../Packages/Core/Kernel/Include -Ibuild/Profile
  DEFINES = -DNS_BUILD -DNS_CONFIG=Profile -DNS_VERSION=2.2.5 -DNS_APP_FRAMEWORK -DNS_STATIC_LIBRARY -DNS_PROFILE -DNS_MINIMUM_LOG_LEVEL=2 -DNS_RENDER_RENDERCONTEXT_EXPORTS -DNS_RENDER_GLRENDERDEVICE_EXPORTS -DNS_APP_DISPLAY_EXPORTS -DNS_RENDER_GLRENDERCONTEXT_PRIVATE -DNS_APP_LAUNCHER_EXPORTS -DNS_APP_PROVIDERS_EXPORTS -DNS_APP_DISPLAYLAUNCHER_EXPORTS -DNS_APP_APPLICATIONLAUNCHER_EXPORTS -DNS_APP_INTERACTIVITY_EXPORTS
  CFLAGS = $(CFLAGS_PROFILE)
  CXXFLAGS = $(CXXFLAGS_PROFILE)
  LDFLAGS = $(LDFLAGS_PROFILE)
else ifeq ($(CONFIG), Release)
  TARGET_DIR = ../../../../Bin/wasm
  TARGET = ../../../../Bin/wasm/NoesisApp.bc
  INTERMEDIATE = build/Release
  LIB_DIRS = 
  LIBS = 
  LIBS_DEPS = 
  INCLUDES = -I../../../Packages/Gui/DependencySystem/Include -I../../../Packages/Render/RenderDevice/Include -I../../../Packages/Math/Utils/Include -I../../../Packages/App/EmscriptenDisplay/Include -I../../../Packages/Gui/CachedFontProvider/Include -I../../../Packages/Drawing/Types/Include -I../../../Packages/Core/NSTL/Include -I../../../Packages/Render/GLRenderDevice/Include -I../../../Packages/Core/Nullable/Include -I../../../Packages/App/Display/Include -I../../../Packages/Core/TypeConverter/Include -I../../../Packages/App/ApplicationLauncher/Include -I../../../Packages/Gui/Animation/Include -I../../../Packages/Gui/Core/Include -I../../../Packages/Math/VectorMath/Include -I../../../Packages/App/Launcher/Include -I../../../../Include -I../../../Packages/Render/GLRenderContext/Include -I../../../Packages/Render/RenderContext/Include -I../../../Packages/Gui/Providers/Include -I../../../Packages/App/DisplayLauncher/Include -I../../../Packages/App/Providers/Include -I../../../../3rdParty/EASTL/local/include -I../../../Packages/App/Interactivity/Include -I../../../Packages/Core/Kernel/Include -Ibuild/Release
  DEFINES = -DNS_BUILD -DNS_CONFIG=Release -DNS_VERSION=2.2.5 -DNS_APP_FRAMEWORK -DNS_STATIC_LIBRARY -DNS_RENDER_RENDERCONTEXT_EXPORTS -DNS_RENDER_GLRENDERDEVICE_EXPORTS -DNS_APP_DISPLAY_EXPORTS -DNS_RENDER_GLRENDERCONTEXT_PRIVATE -DNS_APP_LAUNCHER_EXPORTS -DNS_APP_PROVIDERS_EXPORTS -DNS_APP_DISPLAYLAUNCHER_EXPORTS -DNS_APP_APPLICATIONLAUNCHER_EXPORTS -DNS_APP_INTERACTIVITY_EXPORTS
  CFLAGS = $(CFLAGS_RELEASE)
  CXXFLAGS = $(CXXFLAGS_RELEASE)
  LDFLAGS = $(LDFLAGS_RELEASE)
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
	$(Q)$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) -x c++-header  -c -MMD -MP -o $@ $<

$(INTERMEDIATE)/%.o: ../../../Packages/Render/RenderContext/Src/%.cpp $(PCH) | $(INTERMEDIATE) data
	@echo [CXX] [Render/RenderContext] $(notdir $<)
	$(Q)$(CXX) $(CXXFLAGS) $(PCHFLAGS) $(INCLUDES) $(DEFINES)  -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/Render/RenderContext/Src/%.c | $(INTERMEDIATE) data
	@echo [CC] [Render/RenderContext] $(notdir $<)
	$(Q)$(CC) $(CFLAGS) $(INCLUDES) $(DEFINES)  -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/Render/GLRenderDevice/Src/%.cpp $(PCH) | $(INTERMEDIATE) data
	@echo [CXX] [Render/GLRenderDevice] $(notdir $<)
	$(Q)$(CXX) $(CXXFLAGS) $(PCHFLAGS) $(INCLUDES) $(DEFINES)  -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/Render/GLRenderDevice/Src/%.c | $(INTERMEDIATE) data
	@echo [CC] [Render/GLRenderDevice] $(notdir $<)
	$(Q)$(CC) $(CFLAGS) $(INCLUDES) $(DEFINES)  -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/App/Display/Src/%.cpp $(PCH) | $(INTERMEDIATE) data
	@echo [CXX] [App/Display] $(notdir $<)
	$(Q)$(CXX) $(CXXFLAGS) $(PCHFLAGS) $(INCLUDES) $(DEFINES)  -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/App/Display/Src/%.c | $(INTERMEDIATE) data
	@echo [CC] [App/Display] $(notdir $<)
	$(Q)$(CC) $(CFLAGS) $(INCLUDES) $(DEFINES)  -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/Render/GLRenderContext/Src/%.cpp $(PCH) | $(INTERMEDIATE) data
	@echo [CXX] [Render/GLRenderContext] $(notdir $<)
	$(Q)$(CXX) $(CXXFLAGS) $(PCHFLAGS) $(INCLUDES) $(DEFINES)  -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/Render/GLRenderContext/Src/%.c | $(INTERMEDIATE) data
	@echo [CC] [Render/GLRenderContext] $(notdir $<)
	$(Q)$(CC) $(CFLAGS) $(INCLUDES) $(DEFINES)  -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/App/EmscriptenDisplay/Src/%.cpp $(PCH) | $(INTERMEDIATE) data
	@echo [CXX] [App/EmscriptenDisplay] $(notdir $<)
	$(Q)$(CXX) $(CXXFLAGS) $(PCHFLAGS) $(INCLUDES) $(DEFINES)  -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/App/EmscriptenDisplay/Src/%.c | $(INTERMEDIATE) data
	@echo [CC] [App/EmscriptenDisplay] $(notdir $<)
	$(Q)$(CC) $(CFLAGS) $(INCLUDES) $(DEFINES)  -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/App/Launcher/Src/%.cpp $(PCH) | $(INTERMEDIATE) data
	@echo [CXX] [App/Launcher] $(notdir $<)
	$(Q)$(CXX) $(CXXFLAGS) $(PCHFLAGS) $(INCLUDES) $(DEFINES)  -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/App/Launcher/Src/%.c | $(INTERMEDIATE) data
	@echo [CC] [App/Launcher] $(notdir $<)
	$(Q)$(CC) $(CFLAGS) $(INCLUDES) $(DEFINES)  -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/App/Providers/Src/%.cpp $(PCH) | $(INTERMEDIATE) data
	@echo [CXX] [App/Providers] $(notdir $<)
	$(Q)$(CXX) $(CXXFLAGS) $(PCHFLAGS) $(INCLUDES) $(DEFINES)  -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/App/Providers/Src/%.c | $(INTERMEDIATE) data
	@echo [CC] [App/Providers] $(notdir $<)
	$(Q)$(CC) $(CFLAGS) $(INCLUDES) $(DEFINES)  -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/App/DisplayLauncher/Src/%.cpp $(PCH) | $(INTERMEDIATE) data
	@echo [CXX] [App/DisplayLauncher] $(notdir $<)
	$(Q)$(CXX) $(CXXFLAGS) $(PCHFLAGS) $(INCLUDES) $(DEFINES)  -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/App/DisplayLauncher/Src/%.c | $(INTERMEDIATE) data
	@echo [CC] [App/DisplayLauncher] $(notdir $<)
	$(Q)$(CC) $(CFLAGS) $(INCLUDES) $(DEFINES)  -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/App/ApplicationLauncher/Src/%.cpp $(PCH) | $(INTERMEDIATE) data
	@echo [CXX] [App/ApplicationLauncher] $(notdir $<)
	$(Q)$(CXX) $(CXXFLAGS) $(PCHFLAGS) $(INCLUDES) $(DEFINES)  -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/App/ApplicationLauncher/Src/%.c | $(INTERMEDIATE) data
	@echo [CC] [App/ApplicationLauncher] $(notdir $<)
	$(Q)$(CC) $(CFLAGS) $(INCLUDES) $(DEFINES)  -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/StatsOverlay.xaml.bin.h: ../../../Packages/App/ApplicationLauncher/Src/StatsOverlay.xaml | $(INTERMEDIATE)
	@echo [BIN] [App/ApplicationLauncher] $(notdir $<)
	$(Q)$(BIN2H) "../../../Packages/App/ApplicationLauncher/Src/StatsOverlay.xaml" > "$(INTERMEDIATE)/StatsOverlay.xaml.bin.h" 

$(INTERMEDIATE)/dripicons-v2.ttf.bin.h: ../../../Packages/App/ApplicationLauncher/Src/dripicons-v2.ttf | $(INTERMEDIATE)
	@echo [BIN] [App/ApplicationLauncher] $(notdir $<)
	$(Q)$(BIN2H) "../../../Packages/App/ApplicationLauncher/Src/dripicons-v2.ttf" > "$(INTERMEDIATE)/dripicons-v2.ttf.bin.h" 

$(INTERMEDIATE)/%.o: ../../../Packages/App/Interactivity/Src/%.cpp $(PCH) | $(INTERMEDIATE) data
	@echo [CXX] [App/Interactivity] $(notdir $<)
	$(Q)$(CXX) $(CXXFLAGS) $(PCHFLAGS) $(INCLUDES) $(DEFINES)  -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/%.o: ../../../Packages/App/Interactivity/Src/%.c | $(INTERMEDIATE) data
	@echo [CC] [App/Interactivity] $(notdir $<)
	$(Q)$(CC) $(CFLAGS) $(INCLUDES) $(DEFINES)  -c -MMD -MP -o $@ $<
	$(call FIXSLASHES,$(@:.o=.d))

$(INTERMEDIATE)/init.o: init.cpp $(PCH) | $(INTERMEDIATE)
	@echo [CXX] [NoesisApp] $(notdir $<)
	$(Q)$(CXX) $(CXXFLAGS) $(PCHFLAGS) $(INCLUDES) $(DEFINES)  -c -MMD -MP -o $@ $<

$(TARGET): $(LIBS_DEPS) $(INTERMEDIATE)/init.o $(INTERMEDIATE)/Image.o $(INTERMEDIATE)/Render.RenderContext.o $(INTERMEDIATE)/RenderContext.o $(INTERMEDIATE)/GLRenderDevice.o $(INTERMEDIATE)/Render.GLRenderDevice.o $(INTERMEDIATE)/App.Display.o $(INTERMEDIATE)/Audio.mm.o $(INTERMEDIATE)/Display.o $(INTERMEDIATE)/GLRenderContext.mm.o $(INTERMEDIATE)/Render.GLRenderContext.o $(INTERMEDIATE)/EmscriptenDisplay.o $(INTERMEDIATE)/Gui.EmscriptenDisplay.o $(INTERMEDIATE)/App.Launcher.o $(INTERMEDIATE)/CommandLine.o $(INTERMEDIATE)/Launcher.o $(INTERMEDIATE)/App.Providers.o $(INTERMEDIATE)/EmbeddedFontProvider.o $(INTERMEDIATE)/EmbeddedTextureProvider.o $(INTERMEDIATE)/EmbeddedXamlProvider.o $(INTERMEDIATE)/FileTextureProvider.o $(INTERMEDIATE)/LocalFontProvider.o $(INTERMEDIATE)/LocalTextureProvider.o $(INTERMEDIATE)/LocalXamlProvider.o $(INTERMEDIATE)/App.DisplayLauncher.o $(INTERMEDIATE)/DisplayLauncher.o $(INTERMEDIATE)/App.ApplicationLauncher.o $(INTERMEDIATE)/Application.o $(INTERMEDIATE)/ApplicationLauncher.o $(INTERMEDIATE)/DelegateCommand.o $(INTERMEDIATE)/NotifyPropertyChangedBase.o $(INTERMEDIATE)/Window.o $(INTERMEDIATE)/App.Interactivity.o $(INTERMEDIATE)/AttachableObject.o $(INTERMEDIATE)/Behavior.o $(INTERMEDIATE)/BehaviorCollection.o $(INTERMEDIATE)/ChangePropertyAction.o $(INTERMEDIATE)/ComparisonCondition.o $(INTERMEDIATE)/ComparisonLogic.o $(INTERMEDIATE)/ConditionalExpression.o $(INTERMEDIATE)/ConditionBehavior.o $(INTERMEDIATE)/ControlStoryboardAction.o $(INTERMEDIATE)/DataBindingHelper.o $(INTERMEDIATE)/DataTrigger.Interactivity.o $(INTERMEDIATE)/EventTrigger.Interactivity.o $(INTERMEDIATE)/EventTriggerBase.o $(INTERMEDIATE)/GamepadTrigger.o $(INTERMEDIATE)/GoToStateAction.o $(INTERMEDIATE)/Interaction.o $(INTERMEDIATE)/InvokeCommandAction.o $(INTERMEDIATE)/KeyTrigger.o $(INTERMEDIATE)/LaunchUriOrFileAction.o $(INTERMEDIATE)/MouseDragElementBehavior.o $(INTERMEDIATE)/PlaySoundAction.o $(INTERMEDIATE)/PropertyChangedTrigger.o $(INTERMEDIATE)/RemoveElementAction.o $(INTERMEDIATE)/SelectAction.o $(INTERMEDIATE)/SelectAllAction.o $(INTERMEDIATE)/SetFocusAction.o $(INTERMEDIATE)/StoryboardAction.o $(INTERMEDIATE)/StoryboardCompletedTrigger.o $(INTERMEDIATE)/StoryboardTrigger.o $(INTERMEDIATE)/StyleInteraction.o $(INTERMEDIATE)/TargetedTriggerAction.o $(INTERMEDIATE)/TimerTrigger.o $(INTERMEDIATE)/TranslateZoomRotateBehavior.o $(INTERMEDIATE)/TriggerAction.Interactivity.o $(INTERMEDIATE)/TriggerActionCollection.o $(INTERMEDIATE)/TriggerBase.Interactivity.o $(INTERMEDIATE)/TriggerCollection.o | $(TARGET_DIR)
	@echo [LD] $(notdir $@)
	+$(Q)$(CXX) $(LDFLAGS)  -L../../../../Bin/wasm $(LIB_DIRS) -o $(TARGET) @$(CONFIG).rsp $(LIBS)

-include $(INTERMEDIATE)/init.d $(INTERMEDIATE)/pch.h.d $(INTERMEDIATE)/Image.d $(INTERMEDIATE)/Render.RenderContext.d $(INTERMEDIATE)/RenderContext.d $(INTERMEDIATE)/GLRenderDevice.d $(INTERMEDIATE)/Render.GLRenderDevice.d $(INTERMEDIATE)/App.Display.d $(INTERMEDIATE)/Audio.mm.d $(INTERMEDIATE)/Display.d $(INTERMEDIATE)/GLRenderContext.mm.d $(INTERMEDIATE)/Render.GLRenderContext.d $(INTERMEDIATE)/EmscriptenDisplay.d $(INTERMEDIATE)/Gui.EmscriptenDisplay.d $(INTERMEDIATE)/App.Launcher.d $(INTERMEDIATE)/CommandLine.d $(INTERMEDIATE)/Launcher.d $(INTERMEDIATE)/App.Providers.d $(INTERMEDIATE)/EmbeddedFontProvider.d $(INTERMEDIATE)/EmbeddedTextureProvider.d $(INTERMEDIATE)/EmbeddedXamlProvider.d $(INTERMEDIATE)/FileTextureProvider.d $(INTERMEDIATE)/LocalFontProvider.d $(INTERMEDIATE)/LocalTextureProvider.d $(INTERMEDIATE)/LocalXamlProvider.d $(INTERMEDIATE)/App.DisplayLauncher.d $(INTERMEDIATE)/DisplayLauncher.d $(INTERMEDIATE)/App.ApplicationLauncher.d $(INTERMEDIATE)/Application.d $(INTERMEDIATE)/ApplicationLauncher.d $(INTERMEDIATE)/DelegateCommand.d $(INTERMEDIATE)/NotifyPropertyChangedBase.d $(INTERMEDIATE)/Window.d $(INTERMEDIATE)/App.Interactivity.d $(INTERMEDIATE)/AttachableObject.d $(INTERMEDIATE)/Behavior.d $(INTERMEDIATE)/BehaviorCollection.d $(INTERMEDIATE)/ChangePropertyAction.d $(INTERMEDIATE)/ComparisonCondition.d $(INTERMEDIATE)/ComparisonLogic.d $(INTERMEDIATE)/ConditionalExpression.d $(INTERMEDIATE)/ConditionBehavior.d $(INTERMEDIATE)/ControlStoryboardAction.d $(INTERMEDIATE)/DataBindingHelper.d $(INTERMEDIATE)/DataTrigger.Interactivity.d $(INTERMEDIATE)/EventTrigger.Interactivity.d $(INTERMEDIATE)/EventTriggerBase.d $(INTERMEDIATE)/GamepadTrigger.d $(INTERMEDIATE)/GoToStateAction.d $(INTERMEDIATE)/Interaction.d $(INTERMEDIATE)/InvokeCommandAction.d $(INTERMEDIATE)/KeyTrigger.d $(INTERMEDIATE)/LaunchUriOrFileAction.d $(INTERMEDIATE)/MouseDragElementBehavior.d $(INTERMEDIATE)/PlaySoundAction.d $(INTERMEDIATE)/PropertyChangedTrigger.d $(INTERMEDIATE)/RemoveElementAction.d $(INTERMEDIATE)/SelectAction.d $(INTERMEDIATE)/SelectAllAction.d $(INTERMEDIATE)/SetFocusAction.d $(INTERMEDIATE)/StoryboardAction.d $(INTERMEDIATE)/StoryboardCompletedTrigger.d $(INTERMEDIATE)/StoryboardTrigger.d $(INTERMEDIATE)/StyleInteraction.d $(INTERMEDIATE)/TargetedTriggerAction.d $(INTERMEDIATE)/TimerTrigger.d $(INTERMEDIATE)/TranslateZoomRotateBehavior.d $(INTERMEDIATE)/TriggerAction.Interactivity.d $(INTERMEDIATE)/TriggerActionCollection.d $(INTERMEDIATE)/TriggerBase.Interactivity.d $(INTERMEDIATE)/TriggerCollection.d

clean:
	@echo ==== [NoesisApp] Cleaning '$(CONFIG)' configuration ====
	$(call RMTREE,$(INTERMEDIATE))
	$(call RM,$(TARGET))
