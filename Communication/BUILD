load("@rules_cc//cc:defs.bzl", "cc_library")


cc_library(
    name = "Animation",
    srcs = ["Animation.cpp"],
    hdrs = ["Animation.h"],
    visibility = ["//Communication:__pkg__"],
    deps = [
	"//Communication:IContainer", 
	"//Communication:IAnimation", 
	]
)


cc_library(
    name = "Authorization",
    srcs = ["Authorization.cpp"],
    hdrs = ["Authorization.h"],
    visibility = ["//Communication:__pkg__"],
    deps = [
	"//Communication:IAuthorization", 
	"//Communication:IContainer", 
	]
)


cc_library(
    name = "ClientRequest",
    srcs = ["ClientRequest.cpp"],
    hdrs = ["ClientRequest.h"],
    visibility = ["//Communication:__pkg__"],
    deps = [
	"//Communication:ISerializationGroup", 
	"//Communication:IContainer", 
	"//Communication:IClientRequest", 
	"//Communication:ICommand", 
	"//Communication:IAuthorization", 
	"//Communication:ISerializable", 
	]
)


cc_library(
    name = "Command",
    srcs = ["Command.cpp"],
    hdrs = ["Command.h"],
    visibility = ["//Communication:__pkg__"],
    deps = [
	"//Communication:IContainer", 
	"//Communication:CommandAction", 
	"//Communication:ISerializationGroup", 
	"//Communication:ICommand", 
	]
)


cc_library(
    name = "CommandAction",
    srcs = ["CommandAction.cpp"],
    hdrs = ["CommandAction.h"],
    visibility = ["//Communication:__pkg__"],
    deps = [
	"//Communication:IContainer",
	]
)


cc_library(
    name = "CommandBuilder",
    srcs = ["CommandBuilder.cpp"],
    hdrs = ["CommandBuilder.h"],
    visibility = ["//Communication:__pkg__"],
    deps = [
	"//Communication:IContainer", 
	"//Communication:ICommandBuilder", 
	"//Communication:CommandAction", 
	"//Communication:ICommand", 
	]
)


cc_library(
    name = "Create",
    srcs = ["Create.cpp"],
    hdrs = ["Create.h"],
    visibility = ["//Communication:__pkg__"],
    deps = [
	"//Communication:IContainer", 
	"//Communication:Animation", 
	"//Communication:Authorization", 
	"//Communication:ClientRequest", 
	"//Communication:Command", 
	"//Communication:CommandAction", 
	"//Communication:CommandBuilder", 
	"//Communication:ServerResponse", 
	"//Communication:Status", 
	"//Communication:RemoteTcpServer", 
	"//Communication:TcpHost", 
	"//Communication:TcpClient", 
	"//Communication:TypeConstructor", 
	"//Communication:SerializationGroup", 
	]
)


cc_library(
    name = "IAnimation",
    srcs = ["IAnimation.cpp"],
    hdrs = ["IAnimation.h"],
    visibility = ["//Communication:__pkg__"],
    deps = [
	"//Communication:IContainer", 
	"//Communication:ISerializable", 
	]
)


cc_library(
    name = "IAuthorization",
    srcs = ["IAuthorization.cpp"],
    hdrs = ["IAuthorization.h"],
    visibility = ["//Communication:__pkg__"],
    deps = [
	"//Communication:IContainer", 
	"//Communication:ISerializable", 
	]
)


cc_library(
    name = "IClientRequest",
    srcs = ["IClientRequest.cpp"],
    hdrs = ["IClientRequest.h"],
    visibility = ["//Communication:__pkg__"],
    deps = [
	"//Communication:IContainer", 
	"//Communication:ISerializable", 
	"//Communication:ICommand", 
    "//Communication:IAuthorization"
	]
)


cc_library(
    name = "ICommand",
    srcs = ["ICommand.cpp"],
    hdrs = ["ICommand.h"],
    visibility = ["//Communication:__pkg__"],
    deps = [
	"//Communication:IContainer", 
	"//Communication:CommandAction", 
	"//Communication:ISerializable", 
	]
)


cc_library(
    name = "ICommandBuilder",
    srcs = ["ICommandBuilder.cpp"],
    hdrs = ["ICommandBuilder.h"],
    visibility = ["//Communication:__pkg__"],
    deps = [
	"//Communication:IContainer", 
	"//Communication:ICommand", 
	]
)


cc_library(
    name = "IContainer",
    srcs = [],
    hdrs = ["IContainer.h"],
    visibility = ["//Communication:__pkg__"],
    deps = [
	]
)


cc_library(
    name = "IPV4Address",
    srcs = ["IPV4Address.cpp"],
    hdrs = ["IPV4Address.h"],
    visibility = ["//Communication:__pkg__"],
    deps = [
	"//Communication:IContainer", 
	"//Communication:ISerializable", 
	]
)


cc_library(
    name = "IRemoteResponder",
    srcs = ["IRemoteResponder.cpp"],
    hdrs = ["IRemoteResponder.h"],
    visibility = ["//Communication:__pkg__"],
    deps = [
	"//Communication:IContainer", 
	"//Communication:rPtr", 
	]
)


cc_library(
    name = "IResponder",
    srcs = ["IResponder.cpp"],
    hdrs = ["IResponder.h"],
    visibility = ["//Communication:__pkg__"],
    deps = [
	"//Communication:IContainer", 
	"//Communication:rPtr", 
	]
)


cc_library(
    name = "ISender",
    srcs = ["ISender.cpp"],
    hdrs = ["ISender.h"],
    visibility = ["//Communication:__pkg__"],
    deps = [
	"//Communication:IContainer",
	]
)


cc_library(
    name = "ISerializable",
    srcs = ["ISerializable.cpp"],
    hdrs = ["ISerializable.h"],
    visibility = ["//Communication:__pkg__"],
    deps = [
	"//Communication:IContainer",
	]
)


cc_library(
    name = "ISerializationGroup",
    srcs = ["ISerializationGroup.cpp"],
    hdrs = ["ISerializationGroup.h"],
    visibility = ["//Communication:__pkg__"],
    deps = [
	"//Communication:IContainer", 
	"//Communication:ISerializable", 
	]
)


cc_library(
    name = "IServerResponse",
    srcs = ["IServerResponse.cpp"],
    hdrs = ["IServerResponse.h"],
    visibility = ["//Communication:__pkg__"],
    deps = [
	"//Communication:IContainer", 
	"//Communication:IAnimation", 
	"//Communication:ISerializable", 
	"//Communication:IStatus", 
    "//Communication:CommandAction"
	]
)


cc_library(
    name = "IStatus",
    srcs = ["IStatus.cpp"],
    hdrs = ["IStatus.h"],
    visibility = ["//Communication:__pkg__"],
    deps = [
	"//Communication:IContainer", 
	"//Communication:ISerializable", 
	]
)


cc_library(
    name = "ITypeConstructor",
    srcs = [],
    hdrs = ["ITypeConstructor.h"],
    visibility = ["//Communication:__pkg__"],
    deps = [
	"//Communication:IContainer", 
	"//Communication:ISerializable", 
	]
)


cc_library(
    name = "RemoteTcpServer",
    srcs = ["RemoteTcpServer.cpp"],
    hdrs = ["RemoteTcpServer.h"],
    visibility = ["//Communication:__pkg__"],
    deps = [
	"//Communication:IContainer", 
	"//Communication:rPtr", 
	"//Communication:IRemoteResponder", 
	"//Communication:IPV4Address", 
	]
)


cc_library(
    name = "rPtr",
    srcs = ["rPtr.cpp"],
    hdrs = ["rPtr.h"],
    visibility = ["//Communication:__pkg__"],
    deps = [
	"//Communication:IContainer",
	]
)


cc_library(
    name = "SerializationGroup",
    srcs = ["SerializationGroup.cpp"],
    hdrs = ["SerializationGroup.h"],
    visibility = ["//Communication:__pkg__"],
    deps = [
	"//Communication:IContainer", 
	"//Communication:ISerializable", 
	"//Communication:ISerializationGroup", 
	"//Communication:ITypeConstructor", 
	]
)


cc_library(
    name = "ServerResponse",
    srcs = ["ServerResponse.cpp"],
    hdrs = ["ServerResponse.h"],
    visibility = ["//Communication:__pkg__"],
    deps = [
	"//Communication:IContainer", 
	"//Communication:CommandAction", 
	"//Communication:IAnimation", 
	"//Communication:IServerResponse", 
    "//Communication:ISerializationGroup",
	]
)


cc_library(
    name = "Stat",
    srcs = ["Stat.cpp"],
    hdrs = ["Stat.h"],
    visibility = ["//Communication:__pkg__"],
    deps = [
	"//Communication:IContainer",
	]
)


cc_library(
    name = "Status",
    srcs = ["Status.cpp"],
    hdrs = ["Status.h"],
    visibility = ["//Communication:__pkg__"],
    deps = [
	"//Communication:IContainer", 
	"//Communication:IStatus", 
	]
)


cc_library(
    name = "TcpClient",
    srcs = ["TcpClient.cpp"],
    hdrs = ["TcpClient.h"],
    visibility = ["//Communication:__pkg__"],
    deps = [
	"//Communication:IContainer", 
	"//Communication:IPV4Address", 
	"//Communication:IRemoteResponder", 
	"//Communication:ISender", 
	]
)


cc_library(
    name = "TcpHost",
    srcs = ["TcpHost.cpp"],
    hdrs = ["TcpHost.h"],
    visibility = ["//Communication:__pkg__"],
    deps = [
	"//Communication:IContainer", 
	"//Communication:IPV4Address", 
	"//Communication:IResponder", 
	]
)


cc_library(
    name = "TypeConstructor",
    srcs = ["TypeConstructor.cpp"],
    hdrs = ["TypeConstructor.h"],
    visibility = ["//Communication:__pkg__"],
    deps = [
	"//Communication:ITypeConstructor",
	]
)
