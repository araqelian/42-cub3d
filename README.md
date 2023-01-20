# 🗣 Subject &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cub3d

<br>
<table>
  <tr>
    <td>Program &nbsp;name</td>
    <td>cub3D</td>
  </tr>
   <tr>
    <td>Turn &nbsp;in &nbsp;files</td>
    <td>All &nbsp;your &nbsp;files</td>
  </tr>
   <tr>
    <td>Makefile</td>
    <td>all, &nbsp;clean, &nbsp;fclean, &nbsp;re</td>
  </tr>
   <tr>
    <td>Arguments</td>
    <td>a &nbsp;map &nbsp;in &nbsp;format &nbsp;*.cub</td>
  </tr>
   <tr>
    <td>External &nbsp;functs.</td>
    <td>
      <ul>
        <li>open, &nbsp;close,&nbsp; read, &nbsp;write, &nbsp;printf, &nbsp;malloc, &nbsp;free, &nbsp;perror, &nbsp;strerror, &nbsp;exit
        <li>All &nbsp;functions &nbsp;of &nbsp;the &nbsp;math &nbsp;library &nbsp;(-lm &nbsp;man&nbsp; man &nbsp;3 &nbsp;math)
        <li>All &nbsp;functions &nbsp;of &nbsp;the &nbsp;MinilibX
      </ul>
    </td>
  </tr>
   <tr>
    <td>Libft &nbsp;&nbsp;authorized</td>
    <td>Yes</td>
  </tr>
   <tr>
    <td>Description</td>
    <td>You&nbsp; must &nbsp;create &nbsp;a &nbsp;“realistic” &nbsp;3D &nbsp;graphical &nbsp;representation &nbsp;of &nbsp;the &nbsp;inside &nbsp;of &nbsp;a &nbsp;maze &nbsp;from &nbsp;a<br>first-person &nbsp;perspective. &nbsp;You &nbsp;have &nbsp;to &nbsp;create &nbsp;this&nbsp; representation &nbsp;using &nbsp;the &nbsp;Ray-Casting<br>principles &nbsp;mentioned &nbsp;earlier.</td>
  </tr>
</table>

<br>
The constraints are as follows:<br><br>

<ul>
  <li>You &nbsp;must &nbsp;use &nbsp;the miniLibX.&nbsp; Either&nbsp; the&nbsp; version &nbsp;that &nbsp;is &nbsp;available &nbsp;on &nbsp;the &nbsp;operating&nbsp; system,&nbsp; or &nbsp;from &nbsp;its &nbsp;sources. &nbsp;If &nbsp;you &nbsp;choose &nbsp;to &nbsp;work &nbsp;with &nbsp;the&nbsp; sources, &nbsp;you &nbsp;will &nbsp;need &nbsp;to &nbsp;apply &nbsp;the &nbsp;same &nbsp;rules &nbsp;for &nbsp;your &nbsp;libft &nbsp;as&nbsp; those&nbsp; written &nbsp;above &nbsp;in &nbsp;Common &nbsp;Instructions &nbsp;part.
  <li>The &nbsp;management &nbsp;of &nbsp;your &nbsp;window &nbsp;must&nbsp; remain&nbsp; smooth:&nbsp; changing &nbsp;to &nbsp;another &nbsp;window, &nbsp;minimizing, &nbsp;etc.
  <li>Display &nbsp;different &nbsp;wall &nbsp;textures &nbsp;(the&nbsp; choice &nbsp;is&nbsp; yours) &nbsp;that &nbsp;vary &nbsp;depending &nbsp;on &nbsp;which &nbsp;side &nbsp;the &nbsp;wall &nbsp;is &nbsp;facing &nbsp;(North, &nbsp;South, &nbsp;East, &nbsp;West).
  <li>Your &nbsp;program &nbsp;must&nbsp; be &nbsp;able &nbsp;to &nbsp;set &nbsp;the &nbsp;floor&nbsp; and &nbsp;ceiling &nbsp;colors &nbsp;to &nbsp;two &nbsp;different &nbsp;ones.
  <li>The &nbsp;program &nbsp;displays &nbsp;the &nbsp;image &nbsp;in &nbsp;a&nbsp; window &nbsp;and &nbsp;respects &nbsp;the &nbsp;following &nbsp;rules:
    <ul>
      <li>The&nbsp; left &nbsp;and &nbsp;right&nbsp; arrow &nbsp;keys &nbsp;of&nbsp; the &nbsp;keyboard &nbsp;must &nbsp;allow &nbsp;you &nbsp;to &nbsp;look &nbsp;left &nbsp;and &nbsp;right &nbsp;in &nbsp;the &nbsp;maze.
      <li>The &nbsp;W, &nbsp;A, &nbsp;S, &nbsp;and &nbsp;D &nbsp;keys&nbsp; must &nbsp;allow &nbsp;you &nbsp;to&nbsp; move &nbsp;the &nbsp;point&nbsp; of&nbsp; view&nbsp; through &nbsp;the &nbsp;maze.
      <li>Pressing &nbsp;ESC &nbsp;must &nbsp;close &nbsp;the&nbsp; window &nbsp;and &nbsp;quit &nbsp;the &nbsp;program &nbsp;cleanly.
      <li>Clicking &nbsp;on&nbsp; the&nbsp; red &nbsp;cross &nbsp;on &nbsp;the &nbsp;window’s &nbsp;frame &nbsp;must &nbsp;close&nbsp; the&nbsp; window &nbsp;and&nbsp; quit&nbsp; the &nbsp;program &nbsp;cleanly.
      <li>The &nbsp;use&nbsp; of &nbsp;images&nbsp; of &nbsp;the&nbsp; minilibX&nbsp; is &nbsp;strongly&nbsp; recommended.
    </ul>
    <li>Your &nbsp;program &nbsp;must &nbsp;take &nbsp;as &nbsp;a &nbsp;first&nbsp; argument&nbsp; a&nbsp; scene &nbsp;description &nbsp;file &nbsp;with&nbsp; the &nbsp;.cub &nbsp;extension.
    <ul>
      <li>The &nbsp;map &nbsp;must &nbsp;be&nbsp; composed&nbsp; of&nbsp; only&nbsp; 6 &nbsp;possible &nbsp;characters: &nbsp;0 &nbsp;for &nbsp;an &nbsp;empty &nbsp;space, &nbsp;1&nbsp; for&nbsp; a&nbsp; wall, &nbsp;and &nbsp;N,S,E &nbsp;or&nbsp; W &nbsp;for &nbsp;the &nbsp;player’s&nbsp; start&nbsp; position &nbsp;and&nbsp; spawning &nbsp;orientation.
      <li>The &nbsp;map &nbsp;must &nbsp;be &nbsp;closed/surrounded &nbsp;by &nbsp;walls, &nbsp;if&nbsp; not &nbsp;the&nbsp; program &nbsp;must &nbsp;return &nbsp;an &nbsp;error.
      <li>Except &nbsp;for&nbsp; the&nbsp; map&nbsp; content, &nbsp;each &nbsp;type &nbsp;of&nbsp; element&nbsp; can&nbsp; be &nbsp;separated &nbsp;by &nbsp;one&nbsp; or &nbsp;more &nbsp;empty&nbsp; line(s).
      <li>Except &nbsp;for &nbsp;the &nbsp;map &nbsp;content&nbsp; which &nbsp;always &nbsp;has&nbsp; to&nbsp; be &nbsp;the&nbsp; last, &nbsp;each &nbsp;type&nbsp; of&nbsp; element&nbsp; can&nbsp; be &nbsp;set &nbsp;in&nbsp; any&nbsp; order&nbsp; in&nbsp; the &nbsp;file.
      <li>Except &nbsp;for &nbsp;the &nbsp;map,&nbsp; each&nbsp; type&nbsp; of &nbsp;information&nbsp; from&nbsp; an &nbsp;element&nbsp; can&nbsp; be&nbsp; separated &nbsp;by &nbsp;one &nbsp;or &nbsp;more &nbsp;space(s).
      <li>The &nbsp;map&nbsp; must &nbsp;be&nbsp; parsed &nbsp;as&nbsp; it&nbsp; looks&nbsp; in&nbsp; the&nbsp; file. &nbsp;Spaces &nbsp;are &nbsp;a &nbsp;valid &nbsp;part &nbsp;of&nbsp; the&nbsp; map&nbsp; and&nbsp; are&nbsp; up&nbsp; to&nbsp; you &nbsp;to &nbsp;handle. &nbsp;You &nbsp;must &nbsp;be &nbsp;able &nbsp;to &nbsp;parse &nbsp;any&nbsp; kind &nbsp;of &nbsp;map, &nbsp;as &nbsp;long &nbsp;as &nbsp;it &nbsp;respects &nbsp;the &nbsp;rules &nbsp;of &nbsp;the &nbsp;map.
      <li>If &nbsp;any &nbsp;misconfiguration &nbsp;of &nbsp;any &nbsp;kind &nbsp;is&nbsp; encountered &nbsp;in &nbsp;the &nbsp;file, &nbsp;the &nbsp;program &nbsp;must &nbsp;exit&nbsp; properly &nbsp;and &nbsp;return &nbsp;"Error\n" &nbsp;followed&nbsp; by&nbsp; an &nbsp;explicit&nbsp; error &nbsp;message &nbsp;of &nbsp;your &nbsp;choice.
    </ul>
</ul>
