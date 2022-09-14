const lib = require('lib')({token: process.env.STDLIB_SECRET_TOKEN});

let last_status = await lib.utils.kv['@0.1.16'].entries();

let users = [];
for (let i = 0; i < last_status.length; i++) {
  let [guild_user_id, user_status] = last_status[i];
  let [guild_id, user_id] = guild_user_id.split("_");
  if (guild_id != context.params.event.guild_id) {
    continue;
  }
  let user_data = await lib.discord.guilds['@0.1.0'].members.retrieve({
    user_id: user_id,
    guild_id: guild_id
  });
  let username = `${user_data.user.username}#${user_data.user.discriminator}`;
  if (user_status == "online") {
    users.push(`Online: ${username}`);
  } else {
    var d = new Date(parseInt(user_status)*1000);
    let time_stamp = d.toLocaleString('en-CA', {timeZone: 'Asia/Kolkata', hour12: false});
    users.push(`${time_stamp} IST: ${username}`);
  }
}
users.sort();
users.reverse();
let message = `${users.join("\n")}`;

await lib.discord.channels['@0.2.0'].messages.create({
  channel_id: context.params.event.channel_id,
  content: `<@!${context.params.event.member.user.id}>`,
  embed: {
    description: `${message}`
  }
});
