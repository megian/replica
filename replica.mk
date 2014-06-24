##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=replica
ConfigurationName      :=Debug
WorkspacePath          := "/home/gabriel/Git/replica"
ProjectPath            := "/home/gabriel/Git/replica"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Gabriel Mainberger
Date                   :=06/24/14
CodeLitePath           :="/home/gabriel/.codelite"
LinkerName             :=/usr/bin/g++ 
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="replica.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)uuid 
ArLibs                 :=  "uuid" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++ 
CC       := /usr/bin/gcc 
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/replica-file.c$(ObjectSuffix) $(IntermediateDirectory)/replica-file-header.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/gabriel/Git/replica/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM "main.c"

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) "main.c"

$(IntermediateDirectory)/replica-file.c$(ObjectSuffix): replica-file.c $(IntermediateDirectory)/replica-file.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/gabriel/Git/replica/replica-file.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/replica-file.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/replica-file.c$(DependSuffix): replica-file.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/replica-file.c$(ObjectSuffix) -MF$(IntermediateDirectory)/replica-file.c$(DependSuffix) -MM "replica-file.c"

$(IntermediateDirectory)/replica-file.c$(PreprocessSuffix): replica-file.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/replica-file.c$(PreprocessSuffix) "replica-file.c"

$(IntermediateDirectory)/replica-file-header.c$(ObjectSuffix): replica-file-header.c $(IntermediateDirectory)/replica-file-header.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/gabriel/Git/replica/replica-file-header.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/replica-file-header.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/replica-file-header.c$(DependSuffix): replica-file-header.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/replica-file-header.c$(ObjectSuffix) -MF$(IntermediateDirectory)/replica-file-header.c$(DependSuffix) -MM "replica-file-header.c"

$(IntermediateDirectory)/replica-file-header.c$(PreprocessSuffix): replica-file-header.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/replica-file-header.c$(PreprocessSuffix) "replica-file-header.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/main.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/replica-file.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/replica-file.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/replica-file.c$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/replica-file-header.c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/replica-file-header.c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/replica-file-header.c$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) ".build-debug/replica"


