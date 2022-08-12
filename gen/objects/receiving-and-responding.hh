#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

// https://discord.com/developers/docs/interactions/receiving-and-responding#interaction-object
class ApplicationCommandData{
  public:
    ApplicationCommandData(
        field<Snowflake> id = uninitialized,
        field<std::string> name = uninitialized,
        field<int> type = uninitialized,
        omittable_field<ResolvedData> resolved = omitted,
        omittable_field<std::vector<ApplicationCommandInteractionDataOption> > options = omitted,
        omittable_field<Snowflake> guild_id = omitted,
        omittable_field<Snowflake> target_id = omitted
    ): 
        id(id),
        name(name),
        type(type),
        resolved(resolved),
        options(options),
        guild_id(guild_id),
        target_id(target_id)
    {}
    
    field<Snowflake> id;
    field<std::string> name;
    field<int> type;
    omittable_field<ResolvedData> resolved;
    omittable_field<std::vector<ApplicationCommandInteractionDataOption> > options;
    omittable_field<Snowflake> guild_id;
    omittable_field<Snowflake> target_id;

    friend void to_json(nlohmann::json &j, const ApplicationCommandData &t) {
        //ToJsonExtra
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.resolved.is_omitted()) {j["resolved"] = t.resolved;}
        if(!t.options.is_omitted()) {j["options"] = t.options;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.target_id.is_omitted()) {j["target_id"] = t.target_id;}
    }
};
// https://discord.com/developers/docs/interactions/receiving-and-responding#interaction-object
class MessageComponentData{
  public:
    MessageComponentData(
        field<std::string> custom_id = uninitialized,
        field<int> component_type = uninitialized,
        omittable_field<std::vector<SelectOption> > values = omitted
    ): 
        custom_id(custom_id),
        component_type(component_type),
        values(values)
    {}
    
    field<std::string> custom_id;
    field<int> component_type;
    omittable_field<std::vector<SelectOption> > values;

    friend void to_json(nlohmann::json &j, const MessageComponentData &t) {
        //ToJsonExtra
        if(!t.custom_id.is_omitted()) {j["custom_id"] = t.custom_id;}
        if(!t.component_type.is_omitted()) {j["component_type"] = t.component_type;}
        if(!t.values.is_omitted()) {j["values"] = t.values;}
    }
};
// https://discord.com/developers/docs/interactions/receiving-and-responding#interaction-object
class ModalSubmitData{
  public:
    ModalSubmitData(
        field<std::string> custom_id = uninitialized,
        field<std::vector<MessageComponent> > components = uninitialized
    ): 
        custom_id(custom_id),
        components(components)
    {}
    
    field<std::string> custom_id;
    field<std::vector<MessageComponent> > components;

    friend void to_json(nlohmann::json &j, const ModalSubmitData &t) {
        //ToJsonExtra
        if(!t.custom_id.is_omitted()) {j["custom_id"] = t.custom_id;}
        if(!t.components.is_omitted()) {j["components"] = t.components;}
    }
};
// https://discord.com/developers/docs/interactions/receiving-and-responding#interaction-object
class ResolvedData{
  public:
    ResolvedData(
        omittable_field<std::map<Snowflake, User> > users = omitted,
        omittable_field<std::map<Snowflake, GuildMember> > members = omitted,
        omittable_field<std::map<Snowflake, Role> > roles = omitted,
        omittable_field<std::map<Snowflake, Channel> > channels = omitted,
        omittable_field<std::map<Snowflake, Message> > messages = omitted,
        omittable_field<std::map<Snowflake, Attachment> > attachments = omitted
    ): 
        users(users),
        members(members),
        roles(roles),
        channels(channels),
        messages(messages),
        attachments(attachments)
    {}
    
    omittable_field<std::map<Snowflake, User> > users;
    omittable_field<std::map<Snowflake, GuildMember> > members;
    omittable_field<std::map<Snowflake, Role> > roles;
    omittable_field<std::map<Snowflake, Channel> > channels;
    omittable_field<std::map<Snowflake, Message> > messages;
    omittable_field<std::map<Snowflake, Attachment> > attachments;

    friend void to_json(nlohmann::json &j, const ResolvedData &t) {
        //ToJsonExtra
        if(!t.users.is_omitted()) {j["users"] = t.users;}
        if(!t.members.is_omitted()) {j["members"] = t.members;}
        if(!t.roles.is_omitted()) {j["roles"] = t.roles;}
        if(!t.channels.is_omitted()) {j["channels"] = t.channels;}
        if(!t.messages.is_omitted()) {j["messages"] = t.messages;}
        if(!t.attachments.is_omitted()) {j["attachments"] = t.attachments;}
    }
};
// https://discord.com/developers/docs/interactions/receiving-and-responding#message-interaction-object
class MessageInteraction{
  public:
    MessageInteraction(
        field<Snowflake> id = uninitialized,
        field<InteractionType> type = uninitialized,
        field<std::string> name = uninitialized,
        field<User> user = uninitialized,
        omittable_field<GuildMember> member = omitted
    ): 
        id(id),
        type(type),
        name(name),
        user(user),
        member(member)
    {}
    
    field<Snowflake> id;
    field<InteractionType> type;
    field<std::string> name;
    field<User> user;
    omittable_field<GuildMember> member;

    friend void to_json(nlohmann::json &j, const MessageInteraction &t) {
        //ToJsonExtra
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.name.is_omitted()) {j["name"] = t.name;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
        if(!t.member.is_omitted()) {j["member"] = t.member;}
    }
};
// https://discord.com/developers/docs/interactions/receiving-and-responding#interaction-response-object
class InteractionResponse{
  public:
    InteractionResponse(
        field<InteractionCallbackType> type = uninitialized,
        omittable_field<InteractionCallbackData> data = omitted
    ): 
        type(type),
        data(data)
    {}
    
    field<InteractionCallbackType> type;
    omittable_field<InteractionCallbackData> data;

    friend void to_json(nlohmann::json &j, const InteractionResponse &t) {
        //ToJsonExtra
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.data.is_omitted()) {j["data"] = t.data;}
    }
};
// https://discord.com/developers/docs/interactions/receiving-and-responding#interaction-object
class Interaction{
  public:
    Interaction(
        field<Snowflake> id = uninitialized,
        field<Snowflake> application_id = uninitialized,
        field<InteractionType> type = uninitialized,
        omittable_field<std::variant<ApplicationCommandData, MessageComponentData, ModalSubmitData, ResolvedData> > data = omitted,
        omittable_field<Snowflake> guild_id = omitted,
        omittable_field<Snowflake> channel_id = omitted,
        omittable_field<GuildMember> member = omitted,
        omittable_field<User> user = omitted,
        field<std::string> token = uninitialized,
        field<int> version = uninitialized,
        omittable_field<Message> message = omitted,
        omittable_field<std::string> app_permissions = omitted,
        omittable_field<std::string> locale = omitted,
        omittable_field<std::string> guild_locale = omitted
    ): 
        id(id),
        application_id(application_id),
        type(type),
        data(data),
        guild_id(guild_id),
        channel_id(channel_id),
        member(member),
        user(user),
        token(token),
        version(version),
        message(message),
        app_permissions(app_permissions),
        locale(locale),
        guild_locale(guild_locale)
    {}
    
    field<Snowflake> id;
    field<Snowflake> application_id;
    field<InteractionType> type;
    omittable_field<std::variant<ApplicationCommandData, MessageComponentData, ModalSubmitData, ResolvedData> > data;
    omittable_field<Snowflake> guild_id;
    omittable_field<Snowflake> channel_id;
    omittable_field<GuildMember> member;
    omittable_field<User> user;
    field<std::string> token;
    field<int> version;
    omittable_field<Message> message;
    omittable_field<std::string> app_permissions;
    omittable_field<std::string> locale;
    omittable_field<std::string> guild_locale;

    friend void to_json(nlohmann::json &j, const Interaction &t) {
        //ToJsonExtra
        if(!t.id.is_omitted()) {j["id"] = t.id;}
        if(!t.application_id.is_omitted()) {j["application_id"] = t.application_id;}
        if(!t.type.is_omitted()) {j["type"] = t.type;}
        if(!t.data.is_omitted()) {j["data"] = t.data;}
        if(!t.guild_id.is_omitted()) {j["guild_id"] = t.guild_id;}
        if(!t.channel_id.is_omitted()) {j["channel_id"] = t.channel_id;}
        if(!t.member.is_omitted()) {j["member"] = t.member;}
        if(!t.user.is_omitted()) {j["user"] = t.user;}
        if(!t.token.is_omitted()) {j["token"] = t.token;}
        if(!t.version.is_omitted()) {j["version"] = t.version;}
        if(!t.message.is_omitted()) {j["message"] = t.message;}
        if(!t.app_permissions.is_omitted()) {j["app_permissions"] = t.app_permissions;}
        if(!t.locale.is_omitted()) {j["locale"] = t.locale;}
        if(!t.guild_locale.is_omitted()) {j["guild_locale"] = t.guild_locale;}
    }
};
