<div class="w3-panel w3-display-<?php echo $_POST['align']; ?>">
	<div class="w3-panel w3-blue w3-card-4">
		<form method="post">
			<input type="hidden" name="n_form" value="2">
      <input type="hidden" name="align" value="<?php echo $_POST['align']; ?>">
      <input type="hidden" name="color" value="<?php echo $_POST['color']; ?>">
			<div class="w3-panel">
				<div class="w3-quarter">
					Numero
				</div>
				<div class="w3-rest">
					<input type="number" name="number" class="w3-input" value="0" min="1"/>
				</div>
			</div>
			<div class="w3-panel w3-center">
				<input class="w3-button w3-white" type="submit" value="AVANTI"/>
			</div>
		</form>
	</div>
</div>
